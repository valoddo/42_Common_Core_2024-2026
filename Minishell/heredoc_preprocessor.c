/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_preprocessor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/21 13:16:32 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_heredoc_input(char *delimiter, t_heredoc_buffer \
						*buffer, t_shell_state *state)
{
	char	*line;
	size_t	delimiter_len;

	delimiter_len = ft_strlen(delimiter);
	setup_heredoc_signals();
	while (1 || !g_sigint)
	{
		line = readline("> ");
		if (!line || g_sigint)
			break ;
		if ((ft_strlen(line) == delimiter_len && \
			ft_strncmp(line, delimiter, delimiter_len) == 0))
		{
			free(line);
			break ;
		}
		if (append_to_buffer(buffer, line, state) != 0)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

static int	process_node_heredocs(t_node *node, t_shell_state *state)
{
	t_redir	*redir;

	redir = node->redirs;
	while (redir)
	{
		if (redir->type == TK_HEREDOC_5 && redir->fd == -1)
		{
			if (handle_heredoc_sequence(redir, state) != 0)
				return (1);
		}
		redir = redir->next;
	}
	return (0);
}

int	preprocess_heredocs(t_node *nodes, t_shell_state *state)
{
	t_node	*current;

	current = nodes;
	while (current && !g_sigint)
	{
		if (process_node_heredocs(current, state) != 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int	fill_heredoc_buffer(t_redir *start, t_heredoc_buffer *buffer, \
						t_shell_state *state)
{
	t_redir	*current;
	int		read;

	current = start;
	while (current && current->type == TK_HEREDOC_5)
	{
		if (buffer->capacity > 0 && buffer->content)
		{
			buffer->size = 0;
			buffer->content[0] = '\0';
		}
		read = read_heredoc_input(current->filename, buffer, state);
		if (read != 0)
			return (1);
		current = current->next;
	}
	return (0);
}

void	mark_as_skipped(t_redir *start)
{
	t_redir	*current;

	current = start;
	while (current && current->type == TK_HEREDOC_5)
	{
		current->fd = -2;
		current = current->next;
	}
}
