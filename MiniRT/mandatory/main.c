/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/24 20:44:15 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_check_extention(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 3)
		return (1);
	else if (file[len - 3] != '.' || file[len - 2] != 'r' || \
			file[len - 1] != 't')
		return (1);
	else
		return (0);
}

int	ft_check_file(char *file)
{
	int		tmpfd;
	int		bread;
	char	buf[1];

	tmpfd = open(file, O_DIRECTORY);
	if (tmpfd != -1)
	{
		close(tmpfd);
		return (1);
	}
	tmpfd = open(file, O_RDONLY);
	if (tmpfd == -1)
		return (1);
	bread = read(tmpfd, buf, 1);
	if (bread < 1)
	{
		close(tmpfd);
		return (1);
	}
	if (tmpfd >= 1)
		close(tmpfd);
	return (0);
}

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
		if (error != 0)
		{
			ft_free_scene(scene);
			ft_free_array(array);
			return (error);
		}
		i++;
	}
	ft_free_array(array);
	if (scene->ambient.ratio == -1 || scene->camera.fov == -1 || \
		scene->light.ratio == -1 || scene->num_objects == 0)
		return (ft_free_scene(scene), 4);
	return (0);
}

void	ft_init_scene(t_scene *scene)
{
	scene->ambient.ratio = -1;
	scene->camera.fov = -1;
	scene->light.ratio = -1;
	scene->objects = NULL;
	scene->num_objects = 0;
	scene->selected_object = NULL;
	scene->select_flag = 1;
}

int	main(int argc, char **argv)
{
	t_scene		scene;
	t_window	window;
	int			error;

	error = 0;
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
