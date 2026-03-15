/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:50:21 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 18:23:33 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	ray_at(t_ray *r, double t)
{
	return (vec_add(r->origin, vec_mul(r->dir, t)));
}

t_ray	ft_ray_from_2_points(t_point origin, t_point endpoint)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = ft_normalize(vec_sub(endpoint, origin));
	return (ray);
}

t_ray	generate_ray(t_camera cam, int x, int y)
{
	t_ray		ray;
	t_vector	offset_u;
	t_vector	offset_v;
	t_vector	pixel_pos;
	t_viewport	vp;

	vp = cam.vp;
	offset_u = vec_mul(vp.delta_u, x);
	offset_v = vec_mul(vp.delta_v, y);
	pixel_pos = vec_add(vp.pixel00, offset_u);
	pixel_pos = vec_add(pixel_pos, offset_v);
	ray.origin = cam.pos;
	ray.dir = ft_normalize(vec_sub(pixel_pos, cam.pos));
	return (ray);
}
