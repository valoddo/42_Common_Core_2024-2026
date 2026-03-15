/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:04:47 by vloddo           ###   ########.fr       */
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

int	ft_check_items(char *array, t_scene *scene)
{
	int	i;
	int	error;

	i = 0;
	while (array[i] == ' ' || (array[i] >= 9 && array[i] <= 13))
		i++;
	if (array[i] == 'A' || array[i] == 'C' || array[i] == 'L')
	{
		error = ft_check_elements(array + i, scene);
		if (error != 0)
			return (error);
	}
	else if (array[i] == 's' || array[i] == 'p' || array[i] == 'c')
	{
		error = ft_check_object(array + i, scene);
		if (error != 0)
			return (error);
	}
	return (0);
}

int	ft_check_elements(char *array, t_scene *scene)
{
	if (array[0] == 'A')
	{
		if (ft_check_ambient(array, scene) != 0)
			return (5);
	}
	else if (array[0] == 'C')
	{
		if (ft_check_camera(array, scene) != 0)
			return (6);
	}
	else if (array[0] == 'L')
	{
		if (ft_create_light(array, scene) != 0)
			return (7);
	}
	return (0);
}
