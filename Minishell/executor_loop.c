/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 21:58:31 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_exit_command(t_node *node, t_shell_state *state, \
								int save_out, int save_in)
{
	close(save_out);
	close(save_in);
	exe_exit(node->argv, state);
	return (state->last_status);
}

static int	handle_other_commands(t_node *node, t_shell_state *state)
{
	if (!node->argv || !node->argv[0])
	{
		if (node->redirs && apply_redirects(node->redirs))
			return (1);
		else
			return (0);
	}
	else
	{
		if (node->redirs && apply_redirects(node->redirs))
			return (1);
		else
			return (exec_builtin(node->argv, &state->env));
	}
}

int	exec_in_parent(t_node *node, t_shell_state *state)
{
	int	save_out;
	int	save_in;
	int	status;

	save_out = save_fd(STDOUT_FILENO);
	save_in = save_fd(STDIN_FILENO);
	if (node->argv && node->argv[0] && !ft_strcmp(node->argv[0], "exit"))
		return (handle_exit_command(node, state, save_out, save_in));
	status = handle_other_commands(node, state);
	state->last_status = status;
	switch_fd(save_out, STDOUT_FILENO);
	switch_fd(save_in, STDIN_FILENO);
	close(save_out);
	close(save_in);
	return (state->last_status);
}

void	update_fds_for_next_cmd(t_node *node, int pipe_fd[2], int *prev_fd)
{
	if (node->next)
	{
		close(pipe_fd[1]);
		if (*prev_fd != -1)
			close(*prev_fd);
		*prev_fd = pipe_fd[0];
	}
	else if (*prev_fd != -1)
	{
		close(*prev_fd);
		*prev_fd = -1;
	}
}
