/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sp_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:23:08 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_sp(char *array, t_object *new_obj)
{
	double	radius;
	double	xyz[3];
	int		rgb[3];
	char	**tokens;

	tokens = ft_tokens_creation(array);
	if (!tokens || ft_arrlen(tokens) != 4)
	{
		if (tokens)
			ft_free_array(tokens);
		return (1);
	}
	radius = ft_atof(tokens[2]) / 2.0;
	if (radius <= EPSILON)
		return (ft_free_array(tokens), 1);
	if (ft_parse_rgb(tokens[3], rgb) != 0 || \
		ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_add_sp(new_obj, radius, xyz, rgb);
	return (ft_free_array(tokens), 0);
}

int	ft_add_sp(t_object *new_obj, double radius, double *xyz, int *rgb)
{
	new_obj->id = SP;
	ft_fill_point (&new_obj->pos, xyz);
	ft_fill_vec (&new_obj->dir, (double [3]){0, 0, 0});
	new_obj->radius = radius;
	new_obj->height = -1;
	ft_create_color(&new_obj->color, rgb);
	return (0);
}

int	ft_check_pl(char *array, t_object *new_obj)
{
	double	xyz[3];
	double	vec[3];
	int		rgb[3];
	char	**tokens;

	tokens = ft_tokens_creation(array);
	if (!tokens || ft_arrlen(tokens) != 4)
	{
		if (tokens)
			ft_free_array(tokens);
		return (1);
	}
	if (ft_parse_vec(tokens[2], vec) != 0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_rgb(tokens[3], rgb) != 0 || \
		ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_add_pl(new_obj, vec, xyz, rgb);
	return (ft_free_array(tokens), 0);
}

int	ft_add_pl(t_object *new_obj, double *vec, double *xyz, int *rgb)
{
	new_obj->id = PL;
	ft_fill_point(&new_obj->pos, xyz);
	ft_fill_vec(&new_obj->dir, vec);
	new_obj->radius = -1;
	new_obj->height = -1;
	ft_create_color(&new_obj->color, rgb);
	return (0);
}

char	**ft_tokens_creation(char *array)
{
	char	*new_arr;
	char	**tokens;

	new_arr = ft_trim_and_space(array);
	if (!new_arr)
		return (NULL);
	tokens = ft_split(new_arr, ' ');
	free(new_arr);
	return (tokens);
}
