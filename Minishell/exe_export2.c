/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_export2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 22:15:35 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_export_with_equals(char *arg, char *equals, t_env **env)
{
	char	temp;
	int		export_failed;

	export_failed = 0;
	temp = *equals;
	*equals = '\0';
	if (!is_valid_variable_name(arg))
	{
		print_export_error(arg);
		export_failed = 1;
	}
	else
		handle_key_value_export(arg, equals, env);
	*equals = temp;
	return (export_failed);
}

static int	handle_export_without_equals(char *arg, t_env **env)
{
	if (!is_valid_variable_name(arg))
	{
		print_export_error(arg);
		return (1);
	}
	handle_export_without_value(arg, env);
	return (0);
}

int	handle_single_export(char *arg, t_env **env)
{
	char	*equals;

	equals = strchr(arg, '=');
	if (equals)
		return (handle_export_with_equals(arg, equals, env));
	else
		return (handle_export_without_equals(arg, env));
}

void	handle_export_without_value(char *arg, t_env **env)
{
	t_env	*existing;
	t_env	*new_node;

	existing = find_env_node(*env, arg);
	if (existing)
		existing->exported = 1;
	else
	{
		new_node = create_env_node(arg, NULL, 1);
		if (new_node)
		{
			new_node->next = *env;
			*env = new_node;
		}
	}
}

void	handle_key_value_export(char *arg, char *equals, t_env **env)
{
	char	*key;
	char	*value;
	t_env	*existing;
	t_env	*new_node;

	*equals = '\0';
	key = arg;
	value = equals + 1;
	existing = find_env_node(*env, key);
	if (existing)
	{
		free(existing->value);
		existing->value = ft_strdup(value);
		existing->exported = 1;
	}
	else
	{
		new_node = create_env_node(key, value, 1);
		if (new_node)
		{
			new_node->next = *env;
			*env = new_node;
		}
	}
	*equals = '=';
}
