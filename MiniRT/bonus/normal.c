/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:54:01 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:59:13 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_cylinder_normal(t_hit *hit)
{
	t_object	*cy;
	double		proj;

	cy = hit->obj;
	proj = dot_product(vec_sub(hit->point, cy->pos), cy->dir);
	if (vec_len(vec_sub(hit->point, \
			vec_add(cy->pos, vec_mul(cy->dir, cy->height / 2)))) \
			<= cy->radius)
		hit->normal = cy->dir;
	else if (vec_len(vec_sub(hit->point, \
			vec_sub(cy->pos, vec_mul(cy->dir, cy->height / 2)))) \
			<= cy->radius)
		hit->normal = vec_mul(cy->dir, -1);
	else
		hit->normal = ft_normalize(vec_sub(hit->point, \
				vec_add(cy->pos, vec_mul(cy->dir, proj))));
}

void	ft_cone_normal(t_hit *hit)
{
	t_object	*co;
	t_vector	vp;
	double		h_proj;
	double		angle_rad;
	double		cos2;

	co = hit->obj;
	vp = vec_sub(hit->point, co->pos);
	h_proj = dot_product(vp, co->dir);
	if (h_proj >= co->height - EPSILON)
	{
		hit->normal = vec_mul(co->dir, -1);
		return ;
	}
	angle_rad = (co->angle * M_PI) / 180.0;
	cos2 = cos(angle_rad) * cos(angle_rad);
	hit->normal = vec_sub(vp, vec_mul(co->dir, h_proj / cos2));
	hit->normal = ft_normalize(hit->normal);
}

void	ft_point_normal(t_ray *ray, t_hit *hit)
{
	hit->point = vec_add(ray->origin, vec_mul(ray->dir, hit->t));
	if (hit->obj->id == SP)
		hit->normal = ft_normalize(vec_sub(hit->point, hit->obj->pos));
	else if (hit->obj->id == PL)
		hit->normal = hit->obj->dir;
	else if (hit->obj->id == CY)
		ft_cylinder_normal(hit);
	else if (hit->obj->id == CO)
		ft_cone_normal(hit);
	if (dot_product(ray->dir, hit->normal) > 0)
		hit->normal = vec_mul(hit->normal, -1);
}
