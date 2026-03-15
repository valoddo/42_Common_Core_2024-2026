/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 20:26:19 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/24 20:27:20 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//Handles keyboard input events for the MiniRT window
int	ft_window_event(int keycode, t_window *win)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(win->mlx_ptr);
	else if (keycode == CAM)
	{
		win->scene->select_flag = 1;
		printf("Selected: Camera\n");
	}
	else if (keycode == LIGHT)
	{
		win->scene->select_flag = 2;
		printf("Selected: Light\n");
	}
	else if (keycode == KEY_D || keycode == KEY_A || keycode == KEY_W || \
		keycode == KEY_S || keycode == KEY_Q || keycode == KEY_E)
		ft_translate(win, keycode);
	else if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT || \
		keycode == ARROW_UP || keycode == ARROW_DOWN || \
		keycode == KEY_N || keycode == KEY_M)
		ft_rotate(win, keycode);
	return (0);
}

// Close window and free resources
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

//handle mouse events: 4 = scroll up, 5 = scroll down,
//1 = left click, 3 = right click
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
