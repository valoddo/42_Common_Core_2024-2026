/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:47:55 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 13:31:57 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//initialize a vector
t_vector	ft_create_vec(double x, double y, double z) ///ptr????
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

//initialize a vector
void	ft_fill_vec(t_point *new, double *vec)
{
	new->x = vec[0];
	new->y = vec[1];
	new->z = vec[2];
}

//initialize a point
void	ft_fill_point(t_point *new, double *xyz)
{
	new->x = xyz[0];
	new->y = xyz[1];
	new->z = xyz[2];
}

//vector magnitude (length)
double	vec_len(t_vector v)
{
	double	result;

	result = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (result);
}
