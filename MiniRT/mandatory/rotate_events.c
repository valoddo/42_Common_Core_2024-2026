/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:40:07 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:35:30 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Funzione di rotazione di un vettore attorno a un asse
t_vector	ft_rotate_vector(t_vector v, t_vector axis, int direction)
{
	t_vector	rotated;
	double		c;
	double		s;

	axis = ft_normalize(axis);
	c = cos(ROTATE_STEP * direction);
	s = sin(ROTATE_STEP * direction);
	rotated = vec_add(vec_add(vec_mul(v, c), \
		vec_mul(ft_cross_product(axis, v), s)), \
		vec_mul(axis, dot_product(axis, v) * (1 - c)));
	return (rotated);
}

// Helper per ottenere l'asse di rotazione per la camera - VERSIONE CORRETTA
t_vector	ft_get_rotation_axis(t_camera *cam, int key, int *direction)
{
	t_vector	axis;

	axis = ft_create_vec(0, 0, 0);
	*direction = 0;
	if (key == ARROW_UP)
	{
		axis = cam->right;
		*direction = +1;
	}
	else if (key == ARROW_DOWN)
	{
		axis = cam->right;
		*direction = -1;
	}
	else if (key == ARROW_LEFT)
	{
		axis = ft_create_vec(0, 1, 0);
		*direction = +1;
	}
	else if (key == ARROW_RIGHT)
	{
		axis = ft_create_vec(0, 1, 0);
		*direction = -1;
	}
	return (axis);
}

void	ft_rotate_cam(t_window *win, int key)
{
	t_camera	*cam;
	t_vector	axis;
	t_vector	world_up;
	int			direction;

	cam = &win->scene->camera;
	axis = ft_get_rotation_axis(cam, key, &direction);
	if (direction == 0)
		return ;
	cam->forward = ft_rotate_vector(cam->forward, axis, direction);
	cam->forward = ft_normalize(cam->forward);
	world_up = ft_create_vec(0, 1, 0);
	cam->right = ft_normalize(ft_cross_product(cam->forward, world_up));
	cam->up = ft_normalize(ft_cross_product(cam->right, cam->forward));
	cam->vp = ft_setup_viewport(*cam);
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

void	ft_rotate_obj(t_window *win, int key)
{
	t_object	*obj;
	t_vector	axis;
	int			direction;

	obj = win->scene->selected_object;
	if (!obj)
		return ;
	axis = ft_get_rotation_axis_global(key, &direction);
	if (direction == 0)
		return ;
	if (obj->id == PL)
	{
		obj->dir = ft_rotate_vector(obj->dir, axis, direction);
		obj->dir = ft_normalize(obj->dir);
	}
	else if (obj->id == CY)
	{
		obj->dir = ft_rotate_vector(obj->dir, axis, direction);
		obj->dir = ft_normalize(obj->dir);
	}
	ft_render_img(win, win->scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
}

void	ft_rotate(t_window *win, int key)
{
	if (!win || !win->scene)
		return ;
	if (win->scene->select_flag == 1)
		ft_rotate_cam(win, key);
	else if (win->scene->select_flag == 3 && win->scene->selected_object)
		ft_rotate_obj(win, key);
}
