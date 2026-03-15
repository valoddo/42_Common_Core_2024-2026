/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_math.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:57:25 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 13:30:44 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//dot product: result = a · b
/*used for: compute the angle between vectors, 
	check perpendicularity (dot = 0)'
	used in lighting*/
double	dot_product(t_vector a, t_vector b)
{
	double	result;

	result = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (result);
}

//cross product: result = a × b
/*use cases:
	find a vector perpendicular to two given vectors,
	compute surface normals,
	defining camera orientation (right = cross(forward, up))*/
t_vector	ft_cross_product(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

//return unit vector
t_vector	ft_normalize(t_vector v)
{
	double	len;

	len = vec_len(v);
	return (vec_div(v, len));
}

int	ft_is_normalized(double x, double y, double z)
{
	double	len;

	len = sqrt(x * x + y * y + z * z);
	if (fabs(len - 1.0) <= EPSILON)
		return (1);
	return (0);
}

// Computes the reflection of a vector around a given normal
// returns the reflected vector, pointing away from the surface
t_vector	reflect_vector(t_vector light_dir, t_vector normal)
{
	double		dot;
	t_vector	reflect;

	dot = dot_product(light_dir, normal);
	reflect = vec_sub(light_dir, vec_mul(normal, 2 * dot));
	reflect = vec_opposite(reflect);
	return (reflect);
}
