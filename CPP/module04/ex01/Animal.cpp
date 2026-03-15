/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:34:05 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/02 20:26:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	:type("Animal")
	{
		std::cout << "Animal default constructor called" << std::endl;
	}
	
Animal::Animal(const std::string other)
	:type(other)
	{
		std::cout << "Animal constructor called" << std::endl;
	}
	
Animal::Animal(const Animal& other)
	:type(other.type)
	{
		std::cout << "Animal copy constructor called" << std::endl;
	}	

Animal& Animal::operator=(const Animal& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "Animal assignment operator copy called" << std::endl;
	return(*this);	
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}