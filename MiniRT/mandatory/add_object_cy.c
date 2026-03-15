/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object_cy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:17:20 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	return (0);
}

int	ft_check_object(char *array, t_scene *scene)
{
	t_object	*new_obj;
	int			error_code;

	new_obj = malloc(sizeof(t_object));
	if (!new_obj)
		return (1);
	error_code = ft_parse_object(array, new_obj);
	if (error_code != 0)
		return (free(new_obj), error_code);
	ft_add_obj_list(scene, new_obj);
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

int	ft_check_cy(char *array, t_object *new_obj)
{
	double	xyz[3];
	double	vec[3];
	int		rgb[3];
	char	**tokens;

	tokens = ft_tokens_creation(array);
	if (!tokens || ft_arrlen(tokens) != 6)
	{
		if (tokens)
			ft_free_array(tokens);
		return (1);
	}
	if ((ft_atof(tokens[3]) / 2.0) <= EPSILON || ft_atof(tokens[4]) <= EPSILON)
		return (ft_free_array(tokens), 1);
	if (ft_parse_vec(tokens[2], vec) != 0 || \
		ft_parse_rgb(tokens[5], rgb) != 0 || \
		ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_add_cy(new_obj, vec, xyz, rgb);
	new_obj->radius = ft_atof(tokens[3]) / 2.0;
	new_obj->height = ft_atof(tokens[4]);
	return (ft_free_array(tokens), 0);
}

int	ft_add_cy(t_object *new_obj, double *vec, double *xyz, int *rgb)
{
	new_obj->id = CY;
	ft_fill_point(&new_obj->pos, xyz);
	ft_fill_vec(&new_obj->dir, vec);
	ft_create_color(&new_obj->color, rgb);
	return (0);
}
