/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 21:03:15 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/01 13:05:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array()
{
	array = NULL;
	n = 0;
}

template<typename T>
Array<T>::Array(unsigned int i)
{
	n = i;
    
    if(n != 0)
		array = new T[n]();
    else
        array = NULL;
}

template <typename T>
Array<T>::Array(const Array& other)
{
    n = other.n;
    
    if (n == 0)
        array = NULL;
    else
    {
        array = new T[n];
        for (unsigned int i = 0; i < n; ++i)
            array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        if(array)
            delete[] array;
        n = other.n;
        if (n == 0)
        {
            array = NULL;
        }
        else
        {
            array = new T[n];
            for (unsigned int i = 0; i < n; ++i)
                array[i] = other.array[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    if (array != NULL)
        delete[] array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (n);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= n)
        throw std::out_of_range("Index out of bounds");
    return array[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const
{
    if (i >= n)
        throw std::out_of_range("Index out of bounds");
    return array[i];
}
