/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 16:51:26 by marvin            #+#    #+#             */
/*   Updated: 2026/01/17 16:51:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <string>
#include "Data.hpp"
#include <stdint.h>

class	Serializer
{
	private:
		Serializer();
		Serializer(const  Serializer& other);
		Serializer& operator=(const  Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
  
#endif