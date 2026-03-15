/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/19 16:20:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_invalid_cmd(char *cmd)
{
	if (cmd == NULL || cmd[0] == '\0')
	{
		write(2, "command not found\n", 19);
		return (true);
	}
	return (false);
}

static bool	is_absolute_path(char *cmd)
{
	return (ft_strchr(cmd, '/') != NULL);
}

static char	**get_paths(t_env *env)
{
	char	*path_var;

	path_var = get_env_value("PATH", env);
	if (!path_var)
		return (NULL);
	return (ft_split(path_var, ':'));
}

static char	*search_in_paths(char **paths, char *cmd)
{
	size_t	i;
	char	*full_path;

	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*resolve_path(char *cmd, t_env *env, t_node *node, t_node *head)
{
	char	**paths;
	char	*full_path;

	(void)*node;
	if (is_invalid_cmd(cmd))
		return (NULL);
	if (is_absolute_path(cmd))
		return (ft_strdup(cmd));
	paths = get_paths(env);
	if (!paths)
		return (NULL);
	full_path = search_in_paths(paths, cmd);
	free_split_all(paths);
	if (!full_path)
	{
		if (head && head->token)
			ft_free_token(head->all_tokens);
		ft_free_nodes(head);
		ft_free_env(env);
		write(2, "command not found\n", 19);
		exit(127);
	}
	return (full_path);
}
