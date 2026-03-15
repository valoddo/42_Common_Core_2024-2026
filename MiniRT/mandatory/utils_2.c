/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/29 13:16:58 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_arrlen(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i] != NULL)
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	return (c == ' ' || \
			c == '\t' || \
			c == '\n' || \
			c == '\r' || \
			c == '\v' || \
			c == '\f');
}

char	*ft_trim_and_space(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(ft_strlen(str + i) + 1);
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			new_str[j++] = str[i++];
		else
		{
			new_str[j++] = ' ';
			while (str[i] && ft_isspace(str[i]))
				i++;
		}
	}
	if (j > 0 && new_str[j - 1] == ' ')
		j--;
	new_str[j] = '\0';
	return (new_str);
}

void	ft_print_selected(int i)
{
	if (i == 0)
		printf("Selected: Sphere\n");
	else if (i == 1)
		printf("Selected: Plane\n");
	else if (i == 2)
		printf("Selected: Cylinder\n");
	else if (i == 42)
		printf("\033[1;31mNO OBJECT SELECTED\033[0m\n");
}
