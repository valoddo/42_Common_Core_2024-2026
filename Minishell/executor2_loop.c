/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/21 15:12:37 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_signal_message(int signal)
{
	if (signal == SIGINT)
		ft_putstr_stderr("\n");
	else if (signal == SIGQUIT)
		ft_putstr_stderr("Quit (core dumped)\n");
}

int	wait_for_last(pid_t last_pid, int *exit_status)
{
	int		status;
	pid_t	pid;
	int		signal;

	while (1)
	{
		pid = wait(&status);
		if (pid == -1)
			break ;
		if (pid == 0)
			continue ;
		if (pid == last_pid)
		{
			if (WIFEXITED(status))
				*exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
			{
				signal = WTERMSIG(status);
				*exit_status = 128 + signal;
				if (signal == SIGINT || signal == SIGQUIT)
					print_signal_message(signal);
			}
		}
	}
	return (*exit_status);
}

static int	exec_loop_while(t_node **node_ptr, t_shell_state *state, \
							int *pipe_fd, t_node *head)
{
	pid_t	pid;
	pid_t	last_pid;

	last_pid = -1;
	while (*node_ptr)
	{
		if (create_pipe_if_needed(*node_ptr, pipe_fd))
			return (-2);
		if (should_execute_in_parent(*node_ptr))
			return (exec_in_parent(*node_ptr, state));
		pid = fork();
		if (pid == -1)
			return (write(2, "error: Fork\n", 12), -2);
		if (pid == 0)
			exec_child(*node_ptr, pipe_fd, state->env, head);
		else
			last_pid = pid;
		update_fds_for_next_cmd(*node_ptr, pipe_fd, &pipe_fd[2]);
		*node_ptr = (*node_ptr)->next;
	}
	return (last_pid);
}

int	executor_loop(t_node *node, t_shell_state *state)
{
	pid_t	last_pid;
	t_node	*head;
	int		pipe_fd[3];
	int		ret;

	last_pid = -1;
	head = node;
	pipe_fd[0] = -1;
	pipe_fd[1] = -1;
	pipe_fd[2] = -1;
	ret = exec_loop_while(&node, state, pipe_fd, head);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	if (pipe_fd[1] >= 0)
		close(pipe_fd[1]);
	if (pipe_fd[2] >= 0)
		close(pipe_fd[2]);
	if (ret == -2)
		return (1);
	return (wait_for_last(ret, &state->last_status));
}
