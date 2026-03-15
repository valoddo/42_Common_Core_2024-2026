/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacorrea <cacorrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 10:55:38 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/22 13:21:11 by cacorrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Computes the physical size of the viewport based on the camera FOV
static	t_vp_size	get_viewport_size(double fov)
{
	t_vp_size	size;

	size.width = 2.0 * tan(fov / 2.0);
	size.height = size.width / ASPECT_RATIO;
	return (size);
}

//returns the vectors u(horizontal) and v(vertical) to move in the viewport
static	void	scale_viewport_axes(t_camera cam, t_vp_size vp_size, \
	t_vector *u, t_vector *v)
{
	*u = vec_mul(cam.right, vp_size.width);
	*v = vec_mul(cam.up, vp_size.height);
}

// Finds the position of the top-left corner (pixel [0,0])
static	t_point	find_pixel00(t_camera cam, t_vector u, t_vector v)
{
	t_point	center;
	t_point	corner;

	center = vec_add(cam.pos, cam.forward);
	corner = vec_sub(center, vec_div(u, 2.0));
	corner = vec_sub(corner, vec_div(v, 2.0));
	corner = vec_add(corner, vec_mul(vec_div(u, IMAGE_WIDTH), 0.5));
	corner = vec_add(corner, vec_mul(vec_div(v, IMAGE_HEIGHT), 0.5));
	return (corner);
}

// Sets up the viewport structure for ray generation
// - Computes scaled axes (delta_u, delta_v) per pixel
// - Finds the world-space position of the top-left pixel
t_viewport	ft_setup_viewport(t_camera cam)
{
	t_viewport	vp;
	t_vp_size	vp_size;
	t_vector	u;
	t_vector	v;

	vp_size = get_viewport_size(cam.fov);
	scale_viewport_axes(cam, vp_size, &u, &v);
	vp.delta_u = vec_div(u, IMAGE_WIDTH);
	vp.delta_v = vec_div(v, IMAGE_HEIGHT);
	vp.pixel00 = find_pixel00(cam, u, v);
	return (vp);
}
