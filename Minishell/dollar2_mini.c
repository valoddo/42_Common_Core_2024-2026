/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar2_mini.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 21:44:38 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_expand_normal_var(char **i, t_shell_state *s, char *start)
{
	char	*var_name;
	char	*var_value;

	while (**i && ((**i >= '0' && **i <= '9') || \
					(**i >= 'A' && **i <= 'Z') || \
					(**i >= 'a' && **i <= 'z') || \
					**i == '_'))
		(*i)++;
	if (*i == start)
		return (ft_strdup("$"));
	var_name = ft_strndup(start, *i - start);
	var_value = ft_my_getenv(var_name, s);
	free(var_name);
	if (!var_value)
		var_value = "";
	return (ft_strdup(var_value));
}

static int	get_pid_from_proc_self(void)
{
	char	buffer[256];
	int		fd;
	ssize_t	bytes;
	int		pid;
	int		i;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd < 0)
		return (-1);
	bytes = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (bytes <= 0)
		return (-1);
	buffer[bytes] = '\0';
	pid = 0;
	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
	{
		pid = pid * 10 + (buffer[i] - '0');
		i++;
	}
	return (pid);
}

char	*ft_expand_var(char **input, t_shell_state *state)
{
	char	*start;

	(*input)++;
	start = *input;
	if (**input == '?')
	{
		(*input)++;
		if (g_sigint)
		{
			state->last_status = 130;
			g_sigint = 0;
		}
		return (ft_itoa(state->last_status));
	}
	if (**input == '$')
	{
		(*input)++;
		return (ft_itoa(get_pid_from_proc_self()));
	}
	if (**input == '0')
	{
		(*input)++;
		return (ft_strdup("minishell"));
	}
	return (ft_expand_normal_var(input, state, start));
}
