/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:55:12 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/28 18:22:22 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <string>

template <typename T>
void swap (T &num1, T &num2)
{
	T tmp;

	tmp = num1;
	num1 = num2;
	num2 = tmp;
}

template <typename T>
T min(T num1, T num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

template <typename T>
T max(T num1, T num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

#endif