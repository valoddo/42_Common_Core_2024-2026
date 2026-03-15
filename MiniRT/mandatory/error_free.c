/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 20:13:48 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_error(int code)
{
	if (code == 2)
		write(2, "Error: ./program <file.rt>\n", 28);
	if (code == 3)
		write(2, "Error: insert valid file\n", 26);
	if (code == 4)
		write(2, "Error: missing item\n", 21);
	if (code == 5)
		write(2, "Error: invalid elements in Ambient\n", 36);
	if (code == 6)
		write(2, "Error: invalid elements in Camera\n", 35);
	if (code == 7)
		write(2, "Error: invalid elements in Light\n", 34);
	if (code == 8)
		write(2, "Error: invalid elements in Sphere\n", 35);
	if (code == 9)
		write(2, "Error: invalid elements in Plane\n", 34);
	if (code == 10)
		write(2, "Error: invalid elements in Cylinder\n", 37);
	exit(code);
	return (0);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_free_scene(t_scene *scene)
{
	t_object	*current;
	t_object	*tmp;

	if (!scene)
		return ;
	if (!scene->objects)
		return ;
	current = scene->objects;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}
