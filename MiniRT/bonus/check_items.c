/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:13:27 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

int	ft_check_ambient(char *array, t_scene *scene)
{
	double	ratio;
	int		rgb[3];
	char	**tokens;

	if (scene->ambient.ratio != -1)
		return (1);
	tokens = ft_tokens_creation(array);
	if (!tokens || ft_arrlen(tokens) != 3)
	{
		if (tokens)
			ft_free_array(tokens);
		return (1);
	}
	ratio = ft_atof(tokens[1]);
	if (ratio < 0.0 || ratio > 1.0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_rgb(tokens[2], rgb) != 0)
		return (ft_free_array(tokens), 1);
	scene->ambient.ratio = ratio;
	ft_create_color(&scene->ambient.color, rgb);
	return (ft_free_array(tokens), 0);
}

int	ft_check_camera(char *array, t_scene *scene)
{
	double	fov;
	double	xyz[3];
	double	vec[3];
	char	**tokens;

	if (scene->camera.fov != -1)
		return (1);
	tokens = ft_tokens_creation(array);
	if (!tokens || ft_arrlen(tokens) != 4)
	{
		if (tokens)
			ft_free_array(tokens);
		return (1);
	}
	fov = ft_atof(tokens[3]);
	if (fov < 0 || fov > 180)
		return (ft_free_array(tokens), 1);
	if (ft_parse_vec(tokens[2], vec) != 0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_fill_point(&scene->camera.pos, xyz);
	ft_fill_vec(&scene->camera.vec, vec);
	ft_setup_camera(&scene->camera, fov);
	return (ft_free_array(tokens), 0);
}

int	ft_check_light(char *array, t_light *new_light)
{
	double	ratio;
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
	ratio = ft_atof(tokens[2]);
	if (ratio < 0.0 || ratio > 1.0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_rgb(tokens[3], rgb) != 0)
		return (ft_free_array(tokens), 1);
	if (ft_parse_point(tokens[1], xyz) != 0)
		return (ft_free_array(tokens), 1);
	ft_add_light(new_light, ratio, xyz, rgb);
	return (ft_free_array(tokens), 0);
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
