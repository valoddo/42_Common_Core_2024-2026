/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:35:59 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/29 13:42:44 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_init_window(t_window *win, t_scene *scene)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return (1);
	win->window_ptr = mlx_new_window(win->mlx_ptr, \
			IMAGE_WIDTH, IMAGE_HEIGHT, "miniRT");
	if (win->window_ptr == NULL)
	{
		mlx_destroy_display(win->mlx_ptr);
		return (free(win->mlx_ptr), 1);
	}
	win->img.img = mlx_new_image(win->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (win->img.img == NULL)
		return (ft_close_window(win), 1);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel,
			&win->img.line_length, &win->img.endian);
	win->scene = scene;
	ft_render_img(win, scene);
	mlx_put_image_to_window(win->mlx_ptr, win->window_ptr,
		win->img.img, 0, 0);
	printf("Selected: Camera\n");
	mlx_hook(win->window_ptr, 3, 1L << 1, ft_window_event, win);
	mlx_hook(win->window_ptr, 4, 1L << 2, ft_mouse_event, win);
	mlx_hook(win->window_ptr, 17, 0, (int (*)())mlx_loop_end, win->mlx_ptr);
	return (0);
}

void	ft_render_img(t_window *win, t_scene *scene)
{
	int				x;
	int				y;
	t_viewport		vp;
	unsigned int	color;

	vp = scene->camera.vp;
	y = 0;
	while (y <= IMAGE_HEIGHT - 1)
	{
		x = 0;
		while (x <= IMAGE_WIDTH - 1)
		{
			color = ft_get_color(scene, x, y);
			ft_put_pixel_to_img(&win->img, x, y, color);
			x++;
		}
		y++;
	}
}

int	ft_window_event(int key, t_window *win)
{
	if (key == KEY_ESC)
		mlx_loop_end(win->mlx_ptr);
	else if (key == CAM)
	{
		win->scene->select_flag = 1;
		printf("Selected: Camera\n");
	}
	else if (key == LIGHT)
	{
		win->scene->select_flag = 2;
		printf("Selected: Light\n");
		if (win->scene->selected_light == NULL)
			win->scene->selected_light = win->scene->light;
		else if (win->scene->selected_light->next)
			win->scene->selected_light = win->scene->selected_light->next;
		else
			win->scene->selected_light = win->scene->light;
	}
	else if (key == KEY_D || key == KEY_A || key == KEY_W || \
		key == KEY_S || key == KEY_Q || key == KEY_E)
		ft_translate(win, key);
	else if (key == ARROW_RIGHT || key == ARROW_LEFT || key == ARROW_UP \
		|| key == ARROW_DOWN || key == KEY_N || key == KEY_M)
		ft_rotate(win, key);
	return (0);
}

int	ft_close_window(t_window *win)
{
	if (win->img.img)
		mlx_destroy_image(win->mlx_ptr, win->img.img);
	if (win->window_ptr)
		mlx_destroy_window(win->mlx_ptr, win->window_ptr);
	if (win->mlx_ptr)
	{
		mlx_destroy_display(win->mlx_ptr);
		free(win->mlx_ptr);
		win->mlx_ptr = NULL;
	}
	return (0);
}

int	ft_mouse_event(int button, int x, int y, t_window *win)
{
	(void)x;
	(void)y;
	if (button == 4)
		ft_zoom_in(win);
	else if (button == 5)
		ft_zoom_out(win);
	else if (button == 1)
		ft_click_select(win, x, y);
	else if (button == 3)
		ft_click_deselect(win);
	return (0);
}
