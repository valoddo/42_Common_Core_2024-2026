/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/22 18:23:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_parse_rgb(char *tokens, int *rgb)
{
	char	**colors;

	colors = ft_split(tokens, ',');
	if (!colors || ft_arrlen(colors) != 3)
	{
		if (colors)
			ft_free_array(colors);
		return (1);
	}
	rgb[0] = ft_atoi(colors[0]);
	rgb[1] = ft_atoi(colors[1]);
	rgb[2] = ft_atoi(colors[2]);
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || \
		rgb[1] > 255 || rgb[2] < 0 || rgb[2] > 255)
	{
		ft_free_array(colors);
		return (1);
	}
	ft_free_array(colors);
	return (0);
}

int	ft_parse_vec(char *tokens, double *vec)
{
	char	**coordinates;

	coordinates = ft_split(tokens, ',');
	if (!coordinates || ft_arrlen(coordinates) != 3)
	{
		if (coordinates)
			ft_free_array(coordinates);
		return (1);
	}
	vec[0] = ft_atof(coordinates[0]);
	vec[1] = ft_atof(coordinates[1]);
	vec[2] = ft_atof(coordinates[2]);
	if (vec[0] < -1 || vec[0] > 1 || vec[1] < -1 || \
		vec[1] > 1 || vec[2] < -1 || vec[2] > 1)
	{
		ft_free_array(coordinates);
		return (1);
	}
	if (ft_is_normalized(vec[0], vec[1], vec[2]) != 1)
	{
		ft_free_array(coordinates);
		return (1);
	}
	ft_free_array(coordinates);
	return (0);
}

int	ft_parse_point(char *tokens, double *xyz)
{
	char	**coordinates;

	coordinates = ft_split(tokens, ',');
	if (!coordinates || ft_arrlen(coordinates) != 3)
	{
		if (coordinates)
			ft_free_array(coordinates);
		return (1);
	}
	xyz[0] = ft_atof(coordinates[0]);
	xyz[1] = ft_atof(coordinates[1]);
	xyz[2] = ft_atof(coordinates[2]);
	ft_free_array(coordinates);
	return (0);
}
