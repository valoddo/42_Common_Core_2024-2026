/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:14:47 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 12:30:31 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Solves the quadratic equation and returns the closest positive intersection 
//(smallest t >= 0) to put into ray equation to find a point
double	ft_quadratic_equation(double a, double b, double c)
{
	double	delta;
	double	delta_sqrt;
	double	t[2];

	delta = b * b - (4 * a * c);
	if (delta < 0)
		return (-1);
	delta_sqrt = sqrt(delta);
	t[0] = (-b - delta_sqrt) / (2 * a);
	t[1] = (-b + delta_sqrt) / (2 * a);
	if (t[0] <= t[1])
	{
		if (t[0] >= 0)
			return (t[0]);
	}
	if (t[1] >= 0)
		return (t[1]);
	return (-1);
}

double	ft_sphere_intersection(t_ray *ray, t_object *sp)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;
	double		t;

	t = -42;
	oc = vec_sub(ray->origin, sp->pos);
	a = dot_product(ray->dir, ray->dir);
	b = 2.0 * dot_product(oc, ray->dir);
	c = dot_product(oc, oc) - sp->radius * sp->radius;
	t = ft_quadratic_equation(a, b, c);
	return (t);
}

double	ft_plane_intersection(t_ray *ray, t_object *pl)
{
	double	denom;
	double	t;

	denom = dot_product(ray->dir, pl->dir);
	if (fabs(denom) < EPSILON)
		return (-1);
	t = dot_product(vec_sub(pl->pos, ray->origin), pl->dir) / denom;
	if (t < 0)
		return (-1);
	return (t);
}

double	ft_get_intersection_point(t_ray ray, t_object *obj)
{
	double	t;

	t = -1;
	if (obj->id == SP)
		t = ft_sphere_intersection(&ray, obj);
	else if (obj->id == PL)
		t = ft_plane_intersection(&ray, obj);
	else if (obj->id == CY)
		t = ft_cylinder_intersection(&ray, obj);
	return (t);
}
