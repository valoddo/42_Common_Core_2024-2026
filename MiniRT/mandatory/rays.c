/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:50:21 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/24 18:34:36 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Compute point at distance t: P(t) = origin + t * direction
// ray function
t_point	ray_at(t_ray *r, double t)
{
	return (vec_add(r->origin, vec_mul(r->dir, t)));
}

//generates a ray starting from the camera position through the center of the 
//pixel(x,y) on the viewport 
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

void	ft_init_t_hit(t_hit *hit)
{
	hit->obj = NULL;
	hit->t = -1;
	hit->point = (t_point){0, 0, 0};
	hit->normal = (t_vector){0, 0, 0};
}

// Funzione che inizializza struttura t_hit
t_hit	ft_trace_ray(t_ray ray, t_object *tmp)
{
	t_hit		hit;
	double		t;

	t = -1;
	ft_init_t_hit(&hit);
	while (tmp)
	{
		t = ft_get_intersection_point(ray, tmp);
		if (t >= 0 && (hit.t < 0 || t < hit.t || hit.obj == NULL))
		{
			hit.t = t;
			hit.obj = tmp;
		}
		tmp = tmp->next;
	}
	if (hit.obj != NULL)
		ft_point_normal(&ray, &hit);
	return (hit);
}
