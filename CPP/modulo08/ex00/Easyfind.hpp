/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:50:29 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/01 15:42:52 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <vector>
#include <iostream>

template <typename T>
bool easyfind (T& container, int n)
{
	typename T::iterator it;

	it = container.begin();
	while (it != container.end())
	{
		if (*it == n) //guarda il numero puntato dall’iteratore
			return (true);
		it++;
	}
	return (false);
}

#endif