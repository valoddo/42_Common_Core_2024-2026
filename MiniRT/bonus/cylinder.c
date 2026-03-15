/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:13:48 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 18:13:17 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	ft_cap_intersection(t_ray *ray, t_object *cy, t_point c)
{
	t_object	temp;
	double		t;
	t_point		p;

	temp.pos = c;
	temp.dir = cy->dir;
	t = ft_plane_intersection(ray, &temp);
	if (t < 0)
		return (-1);
	p = vec_add(ray->origin, vec_mul(ray->dir, t));
	if (vec_len(vec_sub(p, c)) > cy->radius)
		return (-1);
	return (t);
}

static t_quadratic_abc	ft_get_quadratic_coefficients(t_ray *ray, t_object *cy)
{
	t_quadratic_abc	q;
	t_vector		oc;
	t_vector		d;
	t_vector		v;
	double			dp[2];

	oc = vec_sub(ray->origin, cy->pos);
	d = ray->dir;
	v = cy->dir;
	dp[0] = dot_product(d, v);
	dp[1] = dot_product(oc, v);
	q.a = dot_product(d, d) - (dp[0] * dp[0]);
	q.b = 2 * (dot_product(d, oc) - (dp[0] * dp[1]));
	q.c = dot_product(oc, oc) - (dp[1] * dp[1]) - (cy->radius * cy->radius);
	return (q);
}

static double	ft_cy_side_intersection(t_ray *ray, t_object *cy)
{
	t_quadratic_abc	q;
	t_point			p;
	t_vector		cp;
	double			proj;
	double			t;

	q = ft_get_quadratic_coefficients(ray, cy);
	t = ft_quadratic_equation(q.a, q.b, q.c);
	if (t < 0)
		return (-1);
	p = vec_add(ray->origin, vec_mul(ray->dir, t));
	cp = vec_sub(p, cy->pos);
	proj = dot_product(cp, cy->dir);
	if (proj < -cy->height / 2 || proj > cy->height / 2)
		return (-1);
	return (t);
}

static double	ft_closest_t(double side, double top, double bottom)
{
	double	t;

	t = -1;
	if (side >= 0)
		t = side;
	if (top >= 0 && (t < 0 || top < t))
		t = top;
	if (bottom >= 0 && (t < 0 || bottom < t))
		t = bottom;
	return (t);
}

double	ft_cylinder_intersection(t_ray	*ray, t_object *cy)
{
	t_point	top_center;
	t_point	bottom_center;
	double	side_t;
	double	top_t;
	double	bottom_t;

	top_center = vec_add(cy->pos, vec_mul(cy->dir, (cy->height / 2)));
	bottom_center = vec_sub(cy->pos, vec_mul(cy->dir, (cy->height / 2)));
	top_t = ft_cap_intersection(ray, cy, top_center);
	bottom_t = ft_cap_intersection(ray, cy, bottom_center);
	side_t = ft_cy_side_intersection(ray, cy);
	return (ft_closest_t(side_t, top_t, bottom_t));
}
