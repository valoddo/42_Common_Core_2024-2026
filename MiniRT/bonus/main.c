/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 20:58:13 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_init_and_check_elements(char *file, t_scene *scene)
{
	char	**array;
	int		i;
	int		error;

	array = ft_create_array(file);
	if (!array)
		return (-1);
	i = 0;
	while (array[i] != NULL)
	{
		error = ft_check_items(array[i], scene);
		if ((error) != 0)
		{
			ft_free_scene(scene);
			ft_free_array(array);
			return (error);
		}
		i++;
	}
	ft_free_array(array);
	if (scene->ambient.ratio == -1 || scene->camera.fov == -1 || \
		scene->num_objects == 0 || scene->num_light == 0)
		return (ft_free_scene(scene), 4);
	return (0);
}

void	ft_init_t_hit(t_hit *hit)
{
	hit->obj = NULL;
	hit->t = -1;
	hit->point = (t_point){0, 0, 0};
	hit->normal = (t_vector){0, 0, 0};
}

t_hit	ft_trace_ray(t_ray ray, t_object *tmp)
{
	t_hit		hit;
	double		t;

	t = -1;
	ft_init_t_hit(&hit);
	while (tmp)
	{
		t = ft_get_intersection_point(ray, tmp);
		if (t >= 0 && (hit.t < 0 || t < hit.t || hit.obj == NULL))
		{
			hit.t = t;
			hit.obj = tmp;
		}
		tmp = tmp->next;
	}
	if (hit.obj != NULL)
		ft_point_normal(&ray, &hit);
	return (hit);
}

void	ft_init_scene(t_scene *scene)
{
	scene->ambient.ratio = -1;
	scene->camera.fov = -1;
	scene->light = NULL;
	scene->objects = NULL;
	scene->num_objects = 0;
	scene->num_light = 0;
	scene->selected_object = NULL;
	scene->selected_light = NULL;
	scene->select_flag = 1;
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_window	window;
	int			error;

	if (argc != 2 || ft_check_extention(argv[1]) != 0)
		return (ft_error(2));
	if (ft_check_file(argv[1]) != 0)
		return (ft_error(3));
	ft_init_scene(&scene);
	error = ft_init_and_check_elements(argv[1], &scene);
	if (error != 0)
		return (ft_error(error));
	if (ft_init_window(&window, &scene) != 0)
		return (ft_error(1));
	mlx_loop(window.mlx_ptr);
	ft_free_scene(&scene);
	ft_close_window(&window);
	return (0);
}
