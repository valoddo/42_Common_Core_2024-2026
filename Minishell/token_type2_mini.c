/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type2_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/19 14:33:37 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*ft_create_token_word(t_token_type type, char *start, int len)
{
	t_token	*new;
	char	*wspaceptr;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = type;
	new->value = ft_strndup(start, len);
	new->wspace = 0;
	wspaceptr = start;
	while (len > 0)
	{
		wspaceptr++;
		len--;
	}
	if (*wspaceptr == ' ')
		new->wspace = 1;
	new->next = NULL;
	return (new);
}

t_token	*ft_word(t_shell_state *state, t_token **new, char **input)
{
	char	*start;
	char	*buf;
	int		var;
	t_token	*res;

	start = *input;
	buf = NULL;
	var = 1;
	res = NULL;
	while (**input && **input != ' ' && **input != '|' && **input != '<' && \
			**input != '>' && **input != '\'' && **input != '"')
	{
		if (var != 2)
			var = ft_check_var(input);
		buf = ft_create_var(buf, input, state);
	}
	if (var == 1)
		res = ft_create_token_word(TK_WORD_0, start, *input - start);
	else if (var == 2)
		res = ft_create_token_dollar(TK_DOLLAR_8, buf, ft_strlen_v(buf), start);
	free(buf);
	*new = res;
	return (res);
}
