/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cy_co.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:06:22 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	ft_check_co(char *array, t_object *new_obj)
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
	if (ft_atof(tokens[3]) <= 0.0 || ft_atof(tokens[3]) >= 90.0 || \
		ft_atof(tokens[4]) <= 0.0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_vec(tokens[2], vec) != 0 || \
		ft_parse_rgb(tokens[5], rgb) != 0 || \
		ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_add_co(new_obj, vec, xyz, rgb);
	new_obj->angle = ft_atof(tokens[3]);
	new_obj->radius = -1;
	new_obj->height = ft_atof(tokens[4]);
	return (ft_free_array(tokens), 0);
}

int	ft_add_co(t_object *new_obj, double *vec, double *xyz, int *rgb)
{
	new_obj->id = CO;
	ft_fill_point(&new_obj->pos, xyz);
	ft_fill_vec(&new_obj->dir, vec);
	ft_create_color(&new_obj->color, rgb);
	return (0);
}
