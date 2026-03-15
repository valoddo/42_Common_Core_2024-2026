/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:12:45 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_create_light(char *array, t_scene *scene)
{
	t_light	*new_light;

	new_light = malloc(sizeof(t_light));
	if (!new_light)
		return (1);
	if (ft_check_light(array, new_light) != 0)
		return (free(new_light), 1);
	ft_add_light_list(scene, new_light);
	return (0);
}

int	ft_add_light(t_light *new_light, double ratio, double *xyz, int *rgb)
{
	ft_fill_point(&new_light->pos, xyz);
	ft_create_color(&new_light->color, rgb);
	new_light->ratio = ratio;
	return (0);
}

void	ft_add_light_list(t_scene *scene, t_light *new_light)
{
	t_light	*tmp;

	new_light->next = NULL;
	if (!scene->light)
		scene->light = new_light;
	else
	{
		tmp = scene->light;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_light;
	}
	scene->num_light += 1;
}

int	ft_parse_object(char *array, t_object *new_obj)
{
	if (array[0] == 's' && array[1] == 'p' && array[2] == ' ')
	{
		if (ft_check_sp(array, new_obj) != 0)
			return (free(new_obj), 8);
	}
	else if (array[0] == 'p' && array[1] == 'l' && array[2] == ' ')
	{
		if (ft_check_pl(array, new_obj) != 0)
			return (free(new_obj), 9);
	}
	else if (array[0] == 'c' && array[1] == 'y' && array[2] == ' ')
	{
		if (ft_check_cy(array, new_obj) != 0)
			return (free(new_obj), 10);
	}
	else if (array[0] == 'c' && array[1] == 'o' && array[2] == ' ')
	{
		if (ft_check_co(array, new_obj) != 0)
			return (free(new_obj), 11);
	}
	return (0);
}

void	ft_add_obj_list(t_scene *scene, t_object *new_obj)
{
	t_object	*tmp;

	new_obj->next = NULL;
	if (!scene->objects)
		scene->objects = new_obj;
	else
	{
		tmp = scene->objects;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_obj;
	}
	scene->num_objects += 1;
}
