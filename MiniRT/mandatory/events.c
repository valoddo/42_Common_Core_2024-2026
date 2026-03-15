/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 15:55:45 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/29 13:21:52 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_zoom_in(t_window	*win)
{
	double	fov;
	double	new_fov;

	if (!win || !win->scene)
		return ;
	fov = win->scene->camera.fov;
	new_fov = fov - ZOOM_STEP;
	if (new_fov < FOV_MIN)
		new_fov = FOV_MIN;
	win->scene->camera.fov = new_fov;
	win->scene->camera.vp = ft_setup_viewport(win->scene->camera);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

void	ft_zoom_out(t_window	*win)
{
	double	fov;
	double	new_fov;

	if (!win || !win->scene)
		return ;
	fov = win->scene->camera.fov;
	new_fov = fov + ZOOM_STEP;
	if (new_fov > FOV_MAX)
		new_fov = FOV_MAX;
	win->scene->camera.fov = new_fov;
	win->scene->camera.vp = ft_setup_viewport(win->scene->camera);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

//select an object by clicking on it
t_hit	ft_find_clicked_object(t_scene *scene, int x, int y)
{
	t_hit		hit;
	t_ray		ray;
	t_object	*obj;
	double		t;

	ft_init_t_hit(&hit);
	ray = generate_ray(scene->camera, x, IMAGE_HEIGHT - y);
	obj = scene->objects;
	while (obj)
	{
		t = ft_get_intersection_point(ray, obj);
		if (t >= 0 && (hit.t < 0 || t < hit.t || hit.obj == NULL))
		{
			hit.t = t;
			hit.obj = obj;
		}
		obj = obj->next;
	}
	return (hit);
}

void	ft_click_select(t_window *win, int x, int y)
{
	t_hit	hit;

	if (!win || !win->scene)
		return ;
	hit = ft_find_clicked_object(win->scene, x, y);
	if (hit.obj)
	{
		win->scene->selected_object = hit.obj;
		win->scene->select_flag = 3;
		ft_print_selected(win->scene->selected_object->id);
	}
	else
	{
		win->scene->selected_object = NULL;
		win->scene->select_flag = 0;
		ft_print_selected(42);
	}
}

void	ft_click_deselect(t_window	*win)
{
	if (!win || !win->scene)
		return ;
	win->scene->selected_object = NULL;
	win->scene->select_flag = 0;
	ft_print_selected(42);
}
