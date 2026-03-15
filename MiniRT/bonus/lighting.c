/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:54:01 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:41:27 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_calculate_ambient(t_scene *scene, t_hit *hit)
{
	t_color	ambient;
	double	ratio;

	ratio = scene->ambient.ratio;
	ambient.r = hit->obj->color.r * scene->ambient.color.r * ratio / 255;
	ambient.g = hit->obj->color.g * scene->ambient.color.g * ratio / 255;
	ambient.b = hit->obj->color.b * scene->ambient.color.b * ratio / 255;
	return (ambient);
}

t_color	ft_calculate_diffuse(t_hit *hit, t_light *light)
{
	t_color		diffuse;
	t_vector	light_dir;
	double		diff_intensity;
	double		factor;

	light_dir = ft_normalize(vec_sub(light->pos, hit->point));
	diff_intensity = dot_product(hit->normal, light_dir);
	if (diff_intensity < 0)
		diff_intensity = 0;
	factor = diff_intensity * light->ratio / 255.0;
	diffuse.r = hit->obj->color.r * light->color.r * factor;
	diffuse.g = hit->obj->color.g * light->color.g * factor;
	diffuse.b = hit->obj->color.b * light->color.b * factor;
	return (diffuse);
}

t_color	ft_calculate_specular(t_scene *scene, t_hit *hit, t_light *light)
{
	t_color2	specular;
	t_vector	light_dir;
	t_vector	view_dir;
	t_vector	reflect_dir;
	double		spec_intensity;

	light_dir = ft_normalize(vec_sub(light->pos, hit->point));
	view_dir = ft_normalize(vec_sub(scene->camera.pos, hit->point));
	reflect_dir = ft_normalize(reflect_vector(light_dir, hit->normal));
	spec_intensity = dot_product(reflect_dir, view_dir);
	if (spec_intensity < 0)
		spec_intensity = 0;
	spec_intensity = pow(spec_intensity, 25.0);
	specular.r = (unsigned int)((double) light->color.r * \
					spec_intensity * light->ratio);
	specular.g = (unsigned int)((double) light->color.g * \
					spec_intensity * light->ratio);
	specular.b = (unsigned int)((double) light->color.b * \
					spec_intensity * light->ratio);
	return (color_clamp(specular));
}

t_color2	ft_char_to_int_color(t_color color)
{
	t_color2	ret;

	ret.r = (unsigned int) color.r;
	ret.b = (unsigned int) color.b;
	ret.g = (unsigned int) color.g;
	return (ret);
}
