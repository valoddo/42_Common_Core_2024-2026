/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 22:25:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	switch_fd(int fd, int target)
{
	if (dup2(fd, target) == -1)
		return (1);
	return (0);
}

int	save_fd(int fd)
{
	int	clone;

	clone = dup(fd);
	if (clone == -1)
	{
		write(2, "Dup\n", 5);
		exit(EXIT_FAILURE);
	}
	return (clone);
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_heredoc_buffer(t_heredoc_buffer *buffer)
{
	if (!buffer)
		return ;
	if (buffer->content)
		free(buffer->content);
	free(buffer);
}

void	clean_exit(t_node *node, t_env *env, int status)
{
	ft_free_token(node->token);
	ft_free_nodes(node);
	ft_free_env(env);
	exit(status);
}
