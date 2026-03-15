/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:13:48 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/24 17:58:18 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	ft_cone_cap_int(t_ray *ray, t_object *co, t_point c, double r)
{
	t_object	temp;
	double		t;
	t_point		p;

	temp.pos = c;
	temp.dir = co->dir;
	t = ft_plane_intersection(ray, &temp);
	if (t < 0)
		return (-1);
	p = vec_add(ray->origin, vec_mul(ray->dir, t));
	if (vec_len(vec_sub(p, c)) > r)
		return (-1);
	return (t);
}

static t_quadratic_abc	ft_cone_quadratic_coefficients(t_ray *ray, t_object *co)
{
	t_quadratic_abc	q;
	t_vector		oc;
	t_vector		d;
	t_vector		v;
	double			k;

	k = tan((co->angle * M_PI) / 180.0);
	k = k * k;
	oc = vec_sub(ray->origin, co->pos);
	d = ray->dir;
	v = co->dir;
	q.a = dot_product(d, d) - (1 + k) * (dot_product(d, v) * dot_product(d, v));
	q.b = 2 * (dot_product(d, oc) - (1 + k) * (dot_product(d, v) * \
				dot_product(oc, v)));
	q.c = dot_product(oc, oc) - (1 + k) * (dot_product(oc, v) * \
				dot_product(oc, v));
	return (q);
}

static double	ft_cone_side_intersection(t_ray *ray, t_object *co)
{
	t_quadratic_abc	q;
	double			t;
	t_point			p;
	t_vector		cp;
	double			proj;

	q = ft_cone_quadratic_coefficients(ray, co);
	t = ft_quadratic_equation(q.a, q.b, q.c);
	if (t < 0)
		return (-1);
	p = vec_add(ray->origin, vec_mul(ray->dir, t));
	cp = vec_sub(p, co->pos);
	proj = dot_product(cp, co->dir);
	if (proj < 0 || proj > co->height)
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

double	ft_cone_intersection(t_ray *ray, t_object *co)
{
	double		side_t;
	double		cap_t;
	double		base_radius;
	t_point		base_center;

	base_radius = co->height * tan((co->angle * M_PI) / 180.0);
	base_center = vec_add(co->pos, vec_mul(co->dir, co->height));
	cap_t = ft_cone_cap_int(ray, co, base_center, base_radius);
	side_t = ft_cone_side_intersection(ray, co);
	return (ft_closest_t(side_t, cap_t, -1));
}
