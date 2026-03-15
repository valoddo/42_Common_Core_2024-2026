/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:50:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/07/20 22:15:56 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_exported_nodes(t_env *env)
{
	int		count;
	t_env	*cur;

	count = 0;
	cur = env;
	while (cur)
	{
		if (cur->exported)
			count++;
		cur = cur->next;
	}
	return (count);
}

static t_env	**create_exported_array(t_env *env, int count)
{
	t_env	**array;
	t_env	*cur;
	int		i;

	array = malloc(count * sizeof(t_env *));
	if (!array)
		return (NULL);
	i = 0;
	cur = env;
	while (cur)
	{
		if (cur->exported)
			array[i++] = cur;
		cur = cur->next;
	}
	return (array);
}

static void	sort_exported_array(t_env **array, int count)
{
	int		i_sort;
	int		j;
	t_env	*temp;

	i_sort = 0;
	while (i_sort < count - 1)
	{
		j = 0;
		while (j < count - i_sort - 1)
		{
			if (ft_strcmp(array[j]->key, array[j + 1]->key) > 0)
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i_sort++;
	}
}

static void	print_exported_array(t_env **array, int count)
{
	int	k;

	k = 0;
	while (k < count)
	{
		if (array[k]->value)
			printf("declare -x %s=\"%s\"\n", array[k]->key, array[k]->value);
		else
			printf("declare -x %s\n", array[k]->key);
		k++;
	}
}

int	print_exported_env(t_env *env)
{
	int		count;
	t_env	**array;

	count = count_exported_nodes(env);
	if (count == 0)
		return (0);
	array = create_exported_array(env, count);
	if (!array)
		return (1);
	sort_exported_array(array, count);
	print_exported_array(array, count);
	free(array);
	return (0);
}
