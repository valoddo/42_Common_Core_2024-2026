/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:19:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_items(char *array, t_scene *scene)
{
	int	i;
	int	error;

	i = 0;
	while (array[i] == ' ' || (array[i] >= 9 && array[i] <= 13))
		i++;
	if (array[i] == 'A' || array[i] == 'C' || array[i] == 'L')
	{
		error = ft_check_elements(array + i, scene);
		if (error != 0)
			return (error);
	}
	else if (array[i] == 's' || array[i] == 'p' || array[i] == 'c')
	{
		error = ft_check_object(array + i, scene);
		if (error != 0)
			return (error);
	}
	return (0);
}

int	ft_check_elements(char *array, t_scene *scene)
{
	if (array[0] == 'A')
	{
		if (ft_check_ambient(array, scene) != 0)
			return (5);
	}
	else if (array[0] == 'C')
	{
		if (ft_check_camera(array, scene) != 0)
			return (6);
	}
	else if (array[0] == 'L')
	{
		if (ft_check_light(array, scene) != 0)
			return (7);
	}
	return (0);
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

int	ft_check_light(char *array, t_scene *scene)
{
	double	ratio;
	double	xyz[3];
	int		rgb[3];
	char	**tokens;

	if (scene->light.ratio != -1)
		return (1);
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
	ft_fill_point(&scene->light.pos, xyz);
	ft_create_color(&scene->light.color, rgb);
	scene->light.ratio = ratio;
	return (ft_free_array(tokens), 0);
}
