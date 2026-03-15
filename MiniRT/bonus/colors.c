/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 12:54:01 by cacorrea          #+#    #+#             */
/*   Updated: 2025/10/27 20:41:11 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_create_color(t_color *new, int *rgb)
{
	new->r = (unsigned char)rgb[0];
	new->g = (unsigned char)rgb[1];
	new->b = (unsigned char)rgb[2];
}

int	ft_t_color_to_int(unsigned char t, t_color c)
{
	int	color;

	color = t << 24 | c.r << 16 | c.g << 8 | c.b;
	return (color);
}

void	ft_put_pixel_to_img(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;

	y = IMAGE_HEIGHT - y;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_color2	color_add(t_color2 c1, t_color2 c2)
{
	t_color2	result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return (result);
}

t_color	color_clamp(t_color2 color)
{
	t_color	ret;

	ret.r = (unsigned char) color.r;
	ret.b = (unsigned char) color.b;
	ret.g = (unsigned char) color.g;
	if (color.r > 255)
		ret.r = 255;
	if (color.g > 255)
		ret.g = 255;
	if (color.b > 255)
		ret.b = 255;
	return (ret);
}
