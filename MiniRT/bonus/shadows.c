/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:14:33 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:53:16 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_in_shadow(t_scene *s, t_point inte, t_object *ta, t_light *light)
{
	t_ray		shadow_ray;
	t_object	*tmp;
	double		t;
	double		light_dist;

	light_dist = vec_len(vec_sub(light->pos, inte));
	tmp = s->objects;
	shadow_ray.dir = ft_normalize(vec_sub(light->pos, inte));
	shadow_ray.origin = vec_add(inte, vec_mul(shadow_ray.dir, EPSILON));
	while (tmp)
	{
		if (tmp == ta)
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

void	ft_calculate_phong_with_shadows(t_scene *scene, t_hit *hit,
									t_light *light, t_color2 *acc)
{
	if (!ft_is_in_shadow(scene, hit->point, hit->obj, light))
	{
		*acc = color_add(*acc, \
			ft_char_to_int_color(ft_calculate_diffuse(hit, light)));
		*acc = color_add(*acc, \
			ft_char_to_int_color(ft_calculate_specular(scene, hit, light)));
	}
}

int	ft_get_color(t_scene *scene, int x, int y)
{
	t_ray		ray;
	t_hit		hit;
	t_object	*tmp_obj;
	t_light		*tmp_light;
	t_color2	total;

	tmp_obj = scene->objects;
	tmp_light = scene->light;
	ray = generate_ray(scene->camera, x, y);
	hit = ft_trace_ray(ray, tmp_obj);
	if (hit.t < 0)
		return (BACKGROUND);
	total = ft_char_to_int_color(ft_calculate_ambient(scene, &hit));
	while (tmp_light)
	{
		ft_calculate_phong_with_shadows(scene, &hit, tmp_light, &total);
		tmp_light = tmp_light->next;
	}
	return (ft_t_color_to_int(0, color_clamp(total)));
}
