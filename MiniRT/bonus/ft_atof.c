/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/08/01 22:10:22 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	n = n * sign;
	return (n);
}

double	ft_dec(char *str)
{
	double	n;
	int		d;
	int		i;

	n = 0;
	d = 1;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		d *= 10;
		i++;
	}
	return (n / d);
}

double	ft_atof(char *str)
{
	int		i;
	double	n;
	int		sign;
	double	nint;
	double	ndec;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	nint = ft_atoi(str + i);
	while (str[i] && str[i] != '.')
		i++;
	ndec = 0;
	if (str[i] == '.')
		ndec = ft_dec(str + i + 1);
	n = (nint + ndec) * sign;
	return (n);
}
