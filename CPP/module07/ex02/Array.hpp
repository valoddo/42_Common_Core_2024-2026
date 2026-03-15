/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:58:40 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/28 19:36:14 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int n;
	public:
		Array();
		Array(unsigned int i);
		Array(const Array<T>& other);
		Array& operator=(const Array<T>& other);
		~Array();
		T& operator[](unsigned int i);
		const T& operator[](unsigned int i) const;
		unsigned int size()const;
};

#include "Array.tpp"

#endif