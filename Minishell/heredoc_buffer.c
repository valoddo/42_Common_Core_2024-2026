/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/21 13:19:48 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	t_heredoc_buffer	*create_heredoc_buffer(void)
{
	t_heredoc_buffer	*buffer;

	buffer = safe_alloc(1, sizeof(t_heredoc_buffer), "heredoc buffer struct");
	if (!buffer)
		return (NULL);
	buffer->content = safe_alloc(4096, sizeof(char), "heredoc content buffer");
	if (!buffer->content)
	{
		free(buffer);
		return (NULL);
	}
	buffer->size = 0;
	buffer->capacity = 4096;
	buffer->content[0] = '\0';
	return (buffer);
}

static int	resize_buffer(t_heredoc_buffer *buffer, size_t new_capacity)
{
	char	*new_content;

	new_content = safe_alloc(new_capacity, sizeof(char), "resized buffer");
	if (!new_content)
		return (1);
	ft_memcpy(new_content, buffer->content, buffer->size);
	new_content[buffer->size] = '\0';
	free(buffer->content);
	buffer->content = new_content;
	buffer->capacity = new_capacity;
	return (0);
}

static int	new_capacity(t_heredoc_buffer *buf, size_t n_size, char *e_line)
{
	size_t	new_capacity;

	new_capacity = buf->capacity * 2;
	while (new_capacity < n_size)
		new_capacity *= 2;
	if (resize_buffer(buf, new_capacity) != 0)
	{
		free(e_line);
		return (1);
	}
	return (0);
}

int	append_to_buffer(t_heredoc_buffer *buffer, char *line, t_shell_state *state)
{
	size_t	needed_size;
	char	*expanded_line;
	int		var;

	var = ft_check_var(&line);
	if (var == 2)
	{
		expanded_line = ft_create_var(NULL, &line, state);
		if (!expanded_line)
			return (1);
		line = expanded_line;
	}
	needed_size = buffer->size + ft_strlen_v(line) + 2;
	if (needed_size > buffer->capacity)
		if (new_capacity(buffer, needed_size, line) == 1)
			return (1);
	ft_strcpy(buffer->content + buffer->size, line);
	buffer->size += ft_strlen_v(line);
	buffer->content[buffer->size] = '\n';
	buffer->size++;
	buffer->content[buffer->size] = '\0';
	if (var == 2)
		free(line);
	return (0);
}

int	handle_heredoc_sequence(t_redir *redir, t_shell_state *state)
{
	t_heredoc_buffer	*buffer;
	int					fd;

	buffer = create_heredoc_buffer();
	if (!buffer)
		return (1);
	if (fill_heredoc_buffer(redir, buffer, state) != 0)
	{
		free_heredoc_buffer(buffer);
		return (1);
	}
	fd = create_fd_from_buffer(buffer);
	if (fd < 0)
	{
		free_heredoc_buffer(buffer);
		return (1);
	}
	redir->fd = fd;
	mark_as_skipped(redir->next);
	free_heredoc_buffer(buffer);
	return (0);
}
