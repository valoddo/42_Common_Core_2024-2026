/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:00:02 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 18:27:51 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	ft_get_move(t_camera *cam, int key)
{
	t_vector	move;

	move = ft_create_vec(0, 0, 0);
	if (key == KEY_D)
		move = vec_mul(cam->right, MOVE_STEP);
	else if (key == KEY_A)
		move = vec_mul(cam->right, -MOVE_STEP);
	else if (key == KEY_W)
		move = vec_mul(cam->forward, MOVE_STEP);
	else if (key == KEY_S)
		move = vec_mul(cam->forward, -MOVE_STEP);
	else if (key == KEY_Q)
		move = vec_mul(cam->up, MOVE_STEP);
	else if (key == KEY_E)
		move = vec_mul(cam->up, -MOVE_STEP);
	return (move);
}

static void	ft_translate_cam(t_window	*win, int key)
{
	t_camera	*cam;
	t_vector	move;

	cam = &win->scene->camera;
	move = ft_get_move(cam, key);
	cam->pos = vec_add(cam->pos, move);
	win->scene->camera.vp = ft_setup_viewport(win->scene->camera);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

static void	ft_translate_light(t_window	*win, int key)
{
	t_light		*light;
	t_vector	move;
	t_camera	*cam;

	light = win->scene->selected_light;
	cam = &win->scene->camera;
	move = ft_get_move(cam, key);
	light->pos = vec_add(light->pos, move);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

static void	ft_translate_obj(t_window	*win, int key)
{
	t_object	*obj;
	t_vector	move;
	t_camera	*cam;

	obj = win->scene->selected_object;
	cam = &win->scene->camera;
	move = ft_get_move(cam, key);
	obj->pos = vec_add(obj->pos, move);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

void	ft_translate(t_window	*win, int key)
{
	if (!win || !win->scene)
		return ;
	if (win->scene->select_flag == 1)
		ft_translate_cam(win, key);
	else if (win->scene->select_flag == 2)
		ft_translate_light(win, key);
	else if (win->scene->select_flag == 3)
		ft_translate_obj(win, key);
}
