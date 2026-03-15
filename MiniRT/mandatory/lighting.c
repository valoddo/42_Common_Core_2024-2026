/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 19:20:54 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/24 19:44:56 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color2	ft_char_to_int_color(t_color color)
{
	t_color2	ret;

	ret.r = (unsigned int) color.r;
	ret.b = (unsigned int) color.b;
	ret.g = (unsigned int) color.g;
	return (ret);
}

// calculates the ambient color component for the hit point
// ambient = object_color * ambient_light_color * ambient_ratio / 255
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

// Calculates the diffuse lighting or lambert lighting
// Its intensity depends
// on the angle between the light direction and the surface normal
// diffuse = object_color * light_color * (max(0, N · L)) * light_ratio / 255
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

// Calculates the specular lighting component
// specular = light_color * (max(0, R · V))^shininess * light_ratio
// sp = specular intensity
t_color	ft_calculate_specular(t_scene *scene, t_hit *hit, t_light *light)
{
	t_color2	specular;
	t_vector	light_dir;
	t_vector	view_dir;
	t_vector	reflect_dir;
	double		sp;

	light_dir = ft_normalize(vec_sub(light->pos, hit->point));
	view_dir = ft_normalize(vec_sub(scene->camera.pos, hit->point));
	reflect_dir = ft_normalize(reflect_vector(light_dir, hit->normal));
	sp = dot_product(reflect_dir, view_dir);
	if (sp < 0)
		sp = 0;
	sp = pow(sp, 25.0);
	specular.r = (unsigned int)((double) light->color.r * (sp * light->ratio));
	specular.g = (unsigned int)((double) light->color.g * (sp * light->ratio));
	specular.b = (unsigned int)((double) light->color.b * (sp * light->ratio));
	return (color_clamp(specular));
}

// Calculates the final color at the intersection point using the
// Phong lighting model
t_color	ft_calculate_phong(t_scene *scene, t_hit *hit)
{
	t_color2	ambient;
	t_color2	diffuse;
	t_color2	specular;
	t_color2	final_color;

	ambient = ft_char_to_int_color(ft_calculate_ambient(scene, hit));
	diffuse = ft_char_to_int_color(ft_calculate_diffuse(hit, &scene->light));
	specular = ft_char_to_int_color \
	(ft_calculate_specular(scene, hit, &scene->light));
	final_color = color_add(ambient, color_add(diffuse, specular));
	return (color_clamp(final_color));
}
