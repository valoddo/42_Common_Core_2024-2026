/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:18:10 by cacorrea          #+#    #+#             */
/*   Updated: 2025/09/25 18:39:52 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//vector addition: result = a + b
t_vector	vec_add(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

//vector subtraction: result = a - b
t_vector	vec_sub(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.x - b.x;
	result.y = a.y - b.y;
	result.z = a.z - b.z;
	return (result);
}

//multiply vector by scalar: result = v * b(scalar)
t_vector	vec_mul(t_vector v, double t)
{
	t_vector	result;

	result.x = v.x * t;
	result.y = v.y * t;
	result.z = v.z * t;
	return (result);
}

//divide vector by a scalar: result = v / b(scalar)
t_vector	vec_div(t_vector v, double t)
{
	t_vector	result;

	if (fabs(t) < EPSILON)
	{
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	else
	{
		result.x = v.x / t;
		result.y = v.y / t;
		result.z = v.z / t;
	}
	return (result);
}

//opposite vector: result = -v
t_vector	vec_opposite(t_vector v)
{
	t_vector	result;

	result.x = -v.x;
	result.y = -v.y;
	result.z = -v.z;
	return (result);
}
