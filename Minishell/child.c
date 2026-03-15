/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/21 14:01:11 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*prepare_command(t_node *node, t_env *env, t_node *head)
{
	char	*bin;

	if (!node->argv || !node->argv[0])
	{
		ft_free_comd(node, head);
		exit(127);
	}
	if (ft_strchr(node->argv[0], '/'))
		return (node->argv[0]);
	if (node->argv[0][0] == '.' && node->argv[0][1] == '\0')
	{
		write(2, "bash: .: filename argument required\n", 37);
		ft_free_comd(node, head);
		ft_free_env(env);
		exit(2);
	}
	bin = resolve_path(node->argv[0], env, node, head);
	if (!bin)
	{
		ft_free_comd(node, head);
		ft_free_env(env);
		exit(127);
	}
	return (bin);
}

static void	execute_command(t_node *node, t_env *env, t_node *head)
{
	char	*bin;
	char	**env_arr;

	bin = prepare_command(node, env, head);
	env_arr = env_to_array(env);
	execve(bin, node->argv, env_arr);
	write(2, "Error directory\n", 17);
	ft_free_token(head->all_tokens);
	free_array(env_arr);
	ft_free_nodes(head);
	ft_free_env(env);
	exit(126);
}

static void	reset_signals_to_default(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_handler = SIG_DFL;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void	exec_child(t_node *node, int pipe_fd[3], t_env *env, t_node *head)
{
	int	pipe_in;
	int	pipe_out[2];

	pipe_in = pipe_fd[2];
	pipe_out[1] = pipe_fd[1];
	pipe_out[0] = pipe_fd[0];
	reset_signals_to_default();
	if (node->next)
		switch_fd(pipe_fd[1], STDOUT_FILENO);
	handle_pipes(pipe_in, pipe_out);
	handle_redirections(node, env, head);
	if (!node->argv || !node->argv[0])
	{
		ft_free_token(head->all_tokens);
		ft_free_nodes(head);
		ft_free_env(env);
		exit(0);
	}
	handle_builtin(node, &env);
	execute_command(node, env, head);
}
