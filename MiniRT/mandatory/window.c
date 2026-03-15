/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:35:59 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/29 13:20:42 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_init_window(t_window *win, t_scene *scene)
{
	win->mlx_ptr = mlx_init();
	if (win->mlx_ptr == NULL)
		return (1);
	win->window_ptr = mlx_new_window(win->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT, \
		"miniRT");
	if (win->window_ptr == NULL)
	{
		mlx_destroy_display(win->mlx_ptr);
		return (free(win->mlx_ptr), 1);
	}
	win->img.img = mlx_new_image(win->mlx_ptr, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (win->img.img == NULL)
		return (ft_close_window(win), 1);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bits_per_pixel, \
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

//generate one ray and get the color(int) to write in the memory (at pixel x, y)
int	ft_get_color(t_scene *scene, int x, int y)
{
	t_ray		ray;
	t_hit		hit;
	t_object	*tmp;
	t_color		final_color;

	tmp = scene->objects;
	ray = generate_ray(scene->camera, x, y);
	hit = ft_trace_ray(ray, tmp);
	if (hit.t >= 0)
	{
		if (ft_is_in_shadow(scene, hit.point, hit.obj) == true)
		{
			final_color = ft_calculate_ambient(scene, &hit);
			return (ft_t_color_to_int(0, final_color));
		}
		final_color = ft_calculate_phong(scene, &hit);
		return (ft_t_color_to_int(0, final_color));
	}
	else
		return (BACKGROUND);
}

static void	ft_cylinder_normal(t_hit *hit, t_object *cy)
{
	t_point		top;
	t_point		bottom;
	t_vector	axis_to_hit;
	double		proj;
	t_point		side_center;

	top = vec_add(cy->pos, vec_mul(cy->dir, cy->height / 2));
	bottom = vec_sub(cy->pos, vec_mul(cy->dir, cy->height / 2));
	axis_to_hit = vec_sub(hit->point, cy->pos);
	proj = dot_product(axis_to_hit, cy->dir);
	if (vec_len(vec_sub(hit->point, top)) <= cy->radius)
		hit->normal = cy->dir;
	else if (vec_len(vec_sub(hit->point, bottom)) <= cy->radius)
		hit->normal = vec_mul(cy->dir, -1);
	else
	{
		side_center = vec_add(cy->pos, vec_mul(cy->dir, proj));
		hit->normal = ft_normalize(vec_sub(hit->point, side_center));
	}
}

void	ft_point_normal(t_ray *ray, t_hit *hit)
{
	hit->point = vec_add(ray->origin, vec_mul(ray->dir, hit->t));
	if (hit->obj->id == SP)
		hit->normal = ft_normalize(vec_sub(hit->point, hit->obj->pos));
	else if (hit->obj->id == PL)
		hit->normal = hit->obj->dir;
	else if (hit->obj->id == CY)
		ft_cylinder_normal(hit, hit->obj);
	if (dot_product(ray->dir, hit->normal) > 0)
		hit->normal = vec_mul(hit->normal, -1);
}
