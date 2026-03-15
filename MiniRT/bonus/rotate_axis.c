/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_axis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 15:40:07 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:38:47 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_set_x_axis(int key, t_vector *axis, int *direction)
{
	if (key == ARROW_UP)
	{
		*axis = ft_create_vec(1, 0, 0);
		*direction = +1;
		return (1);
	}
	if (key == ARROW_DOWN)
	{
		*axis = ft_create_vec(1, 0, 0);
		*direction = -1;
		return (1);
	}
	return (0);
}

int	ft_set_y_axis(int key, t_vector *axis, int *direction)
{
	if (key == ARROW_LEFT)
	{
		*axis = ft_create_vec(0, 1, 0);
		*direction = +1;
		return (1);
	}
	if (key == ARROW_RIGHT)
	{
		*axis = ft_create_vec(0, 1, 0);
		*direction = -1;
		return (1);
	}
	return (0);
}

t_vector	ft_get_rotation_axis_global(int key, int *direction)
{
	t_vector	axis;

	axis = ft_create_vec(0, 0, 0);
	*direction = 0;
	if (ft_set_x_axis(key, &axis, direction))
		return (axis);
	if (ft_set_y_axis(key, &axis, direction))
		return (axis);
	if (key == KEY_N)
	{
		axis = ft_create_vec(0, 0, 1);
		*direction = +1;
	}
	else if (key == KEY_M)
	{
		axis = ft_create_vec(0, 0, 1);
		*direction = -1;
	}
	return (axis);
}
