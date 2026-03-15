/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:28:58 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 19:22:22 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// handle cases where camera is looking up or down because cros product
//will be 0
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
