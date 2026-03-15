/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:28:58 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 16:59:55 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_setup_camera(t_camera *cam, double fov)
{
	t_vector	world_up;

	if (cam->vec.x == 0.0 && cam->vec.z == 0.0 && \
		(cam->vec.y == 1.0 || cam->vec.y == -1.0))
		world_up = ft_create_vec(1.0, 0.0, 0.0);
	else
		world_up = ft_create_vec(0.0, 1.0, 0.0);
	cam->forward = cam->vec;
	cam->right = ft_normalize(ft_cross_product(cam->forward, world_up));
	cam->up = ft_normalize(ft_cross_product(cam->right, cam->forward));
	cam->fov = fov * (M_PI / 180.0);
	cam->vp = ft_setup_viewport(*cam);
}
