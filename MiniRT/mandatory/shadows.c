/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:14:33 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/24 18:31:05 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_in_shadow(t_scene *scene, t_point intersection, t_object *target)
{
	t_ray		shadow_ray;
	t_object	*tmp;
	double		t;
	double		light_dist;

	light_dist = vec_len(vec_sub(scene->light.pos, intersection));
	tmp = scene->objects;
	shadow_ray.dir = ft_normalize(vec_sub(scene->light.pos, intersection));
	shadow_ray.origin = vec_add(intersection, vec_mul(shadow_ray.dir, EPSILON));
	while (tmp)
	{
		if (tmp->pos.x == scene->light.pos.x && tmp->pos.y == \
			scene->light.pos.y && tmp->pos.z == scene->light.pos.z)
			return (false);
		if (tmp == target)
		{
			tmp = tmp->next;
			continue ;
		}
		t = ft_get_intersection_point(shadow_ray, tmp);
		if (t > 0 && t < light_dist)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}
