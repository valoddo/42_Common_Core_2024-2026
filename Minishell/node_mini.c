/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 04:37:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_is_char_token(t_node *new)
{
	if ((new->token->type == TK_S_QUOTE_6 || new->token->type == TK_D_QUOTE_7 \
		|| new->token->type == TK_DOLLAR_8) || new->token->type == TK_WORD_0)
		return (0);
	else
		return (1);
}

t_node	*ft_node(t_token *token)
{
	t_token	*start;
	t_token	*tmp;
	t_node	*new;
	t_node	*head;

	head = NULL;
	start = token;
	tmp = token;
	while (tmp)
	{
		while (tmp && tmp->type != TK_PIPE_1)
			tmp = tmp->next;
		new = ft_get_node(start);
		if (!new)
			return (ft_free_nodes(head));
		if (ft_is_char_token(new) == 0)
			new->argv = ft_build_argv(start, tmp);
		if (!new->argv && new->redirs == NULL)
			return (ft_free_nodes(new));
		ft_create_node(&head, new);
		ft_advance_tokens(&start, &tmp);
	}
	return (head);
}

static t_token	*ft_find_first_cmd_token(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp && tmp->type != TK_PIPE_1)
	{
		if (tmp->type == TK_WORD_0 || \
			tmp->type == TK_S_QUOTE_6 || \
			tmp->type == TK_D_QUOTE_7 || \
			tmp->type == TK_DOLLAR_8)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

static void	ft_process_redirections(t_node *node)
{
	t_token	*tmp;

	tmp = node->token;
	while (tmp && tmp->type != TK_PIPE_1)
	{
		if (tmp->type >= TK_REDIR_IN_2 && tmp->type <= TK_HEREDOC_5)
		{
			ft_add_redirection(node, tmp);
			if (tmp->next)
				tmp = tmp->next;
		}
		tmp = tmp->next;
	}
}

t_node	*ft_get_node(t_token *token)
{
	t_node	*new;
	t_token	*first_cmd_token;

	new = calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->all_tokens = token;
	new->head = NULL;
	new->redirs = NULL;
	new->token = token;
	new->argv = NULL;
	new->next = NULL;
	first_cmd_token = ft_find_first_cmd_token(token);
	ft_process_redirections(new);
	if (first_cmd_token)
		new->token = first_cmd_token;
	else
		new->token = NULL;
	return (new);
}
