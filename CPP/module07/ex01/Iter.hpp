/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:39:28 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/29 11:07:50 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>

template <typename T>
void iter(T *array, int const length, void (*function)(T&))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void iter(T *array, int const length, void (*function)(T const&))
{
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void print(T const& x)
{
    std::cout << x << " ";
}


#endif