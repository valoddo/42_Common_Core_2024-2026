/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_argv_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/19 14:53:18 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_argument_token(t_token_type type)
{
	return (type == TK_WORD_0 || type == TK_S_QUOTE_6
		|| type == TK_D_QUOTE_7 || type == TK_DOLLAR_8);
}

t_token	*skip_redirection_tokens(t_token *tmp, t_token *end)
{
	while (tmp && tmp != end && (tmp->type >= TK_REDIR_IN_2 \
			&& tmp->type <= TK_HEREDOC_5))
	{
		tmp = tmp->next;
		if (tmp == end || !tmp)
			return (NULL);
		tmp = tmp->next;
	}
	return (tmp);
}

int	ft_count_tokens(t_token *start, t_token *end)
{
	t_token	*cur;
	int		count;

	cur = start;
	count = 0;
	while (cur && cur != end)
	{
		cur = skip_redirection_tokens(cur, end);
		if (!cur || cur == end)
			break ;
		if (is_argument_token(cur->type))
		{
			count++;
			while (cur->wspace == 0 && cur->next != NULL && cur->next != end)
			{
				if (!is_argument_token(cur->type))
					break ;
				cur = cur->next;
			}
		}
		if (is_argument_token(cur->type))
			cur = cur->next;
	}
	return (count);
}

char	**ft_build_argv(t_token *start, t_token *end)
{
	char	**argv;
	int		j;

	j = ft_count_tokens(start, end);
	argv = malloc((j + 1) * sizeof(char *));
	if (!argv)
		return (NULL);
	argv = populate_argv(argv, start, end);
	return (argv);
}

char	**free_argv(char **argv, int i)
{
	while (i-- > 0)
		free(argv[i]);
	free(argv);
	return (NULL);
}
