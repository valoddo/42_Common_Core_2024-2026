/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 22:01:53 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipes(int pipe_in, int pipe_out[2])
{
	if (pipe_in != -1)
		switch_fd(pipe_in, STDIN_FILENO);
	if (pipe_out[0] != -1)
		close(pipe_out[0]);
	if (pipe_out[1] != -1)
		close(pipe_out[1]);
	if (pipe_in != -1)
		close(pipe_in);
}

void	handle_redirections(t_node *node, t_env *env, t_node *head)
{
	if (node->redirs && apply_redirects(node->redirs) != 0)
	{
		ft_free_token(node->all_tokens);
		ft_free_nodes(head);
		ft_free_env(env);
		exit(1);
	}
}

void	handle_builtin(t_node *node, t_env **env)
{
	int	status;

	if (is_builtin(node->argv[0]))
	{
		status = exec_builtin(node->argv, env);
		clean_exit(node, *env, status);
	}
}

void	ft_free_comd(t_node *node, t_node *head)
{
	ft_free_token(node->all_tokens);
	ft_free_nodes(head);
}
