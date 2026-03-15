/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_type3_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/18 14:48:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*ft_create_token_dollar(t_token_type t, char *b, int l, char *s)
{
	t_token	*new;
	char	*wspaceptr;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = t;
	new->value = ft_strndup(b, l);
	new->wspace = 0;
	wspaceptr = s;
	while (*wspaceptr && \
			((*wspaceptr >= '0' && *wspaceptr <= '9') || \
			(*wspaceptr >= 'A' && *wspaceptr <= 'Z') || \
			(*wspaceptr >= 'a' && *wspaceptr <= 'z') || \
			*wspaceptr == '_' || *wspaceptr == '$'))
		wspaceptr++;
	if (*wspaceptr == '"' )
		wspaceptr++;
	if (*wspaceptr == ' ')
		new->wspace = 1;
	new->next = NULL;
	return (new);
}

static t_token	*ft_create_token_quote(t_token_type t, char *s, int l, int ws)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->type = t;
	new->value = ft_strndup(s, l);
	new->wspace = ws;
	new->next = NULL;
	return (new);
}

static char	*ft_process_dquote_content(t_shell_state *s, char **i, int *var)
{
	char	*buffer;

	buffer = NULL;
	while (**i && **i != '"')
	{
		if (*var != 2)
			*var = ft_check_var(i);
		buffer = ft_create_var(buffer, i, s);
	}
	return (buffer);
}

t_token	*ft_dquote(t_shell_state *s, t_token *t, t_token **n, char **i)
{
	char	*start;
	char	*buf;
	int		var;
	int		wspace;

	var = 1;
	start = *i;
	buf = NULL;
	(*i)++;
	start = *i;
	if (ft_check_dquote(s, t, start) == 1)
		return (NULL);
	buf = ft_process_dquote_content(s, i, &var);
	wspace = ft_check_token_space(i);
	if (var == 1)
		*n = ft_create_token_quote(TK_D_QUOTE_7, start, *i - start, wspace);
	else if (var == 2)
		*n = ft_create_token_dollar(TK_DOLLAR_8, buf, ft_strlen_v(buf), start);
	if (buf)
		free(buf);
	(*i)++;
	return (*n);
}

t_token	*ft_squote(t_token *token, t_token **new, char **input)
{
	char	*start;
	int		wspace;

	(void)token;
	(*input)++;
	start = *input;
	while (**input && **input != '\'')
		(*input)++;
	if (**input != '\'')
		return (ft_putstr_stderr("Unclosed single quote\n"), NULL);
	wspace = ft_check_token_space(input);
	*new = ft_create_token_quote(TK_S_QUOTE_6, start, *input - start, wspace);
	(*input)++;
	return (*new);
}
