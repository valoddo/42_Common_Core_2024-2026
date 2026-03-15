/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_argv2_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/19 14:52:21 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_concatenate_tokens(t_token *s, t_token *e, char *buf, int f_arg)
{
	t_token	*current;
	char	*ptr;

	ptr = buf;
	current = s;
	while (1)
	{
		ft_strcpy(ptr, current->value);
		ptr += ft_strlen(current->value);
		if (current == e)
			break ;
		current = current->next;
	}
	if (!f_arg && e->wspace == 1 && current != e)
	{
		*ptr = ' ';
		ptr++;
	}
	*ptr = '\0';
}

static char	*ft_strjoin_token_group(t_token *start, t_token *end, int first_arg)
{
	char	*result;
	size_t	total_len;
	t_token	*current;

	total_len = 0;
	current = start;
	while (1)
	{
		total_len += ft_strlen(current->value);
		if (current == end)
			break ;
		current = current->next;
	}
	if (!first_arg && end->wspace == 1 && current != end)
		total_len++;
	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	ft_concatenate_tokens(start, end, result, first_arg);
	return (result);
}

static t_token	*process_token_group(t_token *c, t_token *e, char **rs, int fa)
{
	t_token	*group_start;
	t_token	*group_end;

	group_start = c;
	group_end = c;
	while (c->wspace == 0 && c->next != NULL && c->next != e)
	{
		c = c->next;
		if (!is_argument_token(c->type))
			break ;
		group_end = c;
	}
	*rs = ft_strjoin_token_group(group_start, group_end, fa);
	return (c);
}

static int	process_argument_token(t_token **c, t_token *e, char **a, int *i)
{
	char	*group_str;
	t_token	*processed_cur;
	int		first_arg;

	first_arg = (*i == 0);
	group_str = NULL;
	processed_cur = process_token_group(*c, e, &group_str, first_arg);
	if (!group_str)
		return (0);
	a[(*i)++] = group_str;
	*c = processed_cur;
	return (1);
}

char	**populate_argv(char **argv, t_token *start, t_token *end)
{
	t_token	*cur;
	int		i;

	cur = start;
	i = 0;
	while (cur && cur != end)
	{
		cur = skip_redirection_tokens(cur, end);
		if (!cur || cur == end)
			break ;
		if (is_argument_token(cur->type))
		{
			if (!process_argument_token(&cur, end, argv, &i))
				return (free_argv(argv, i));
			cur = skip_redirection_tokens(cur, end);
			if (!cur || cur == end)
				break ;
		}
		if (cur->next)
			cur = cur->next;
		else
			break ;
	}
	argv[i] = NULL;
	return (argv);
}
