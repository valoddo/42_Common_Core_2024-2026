/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:38:36 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/01 15:35:40 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	:type("Animal")
	{
		std::cout << "Animal default constructor created" << std::endl;
	}

Animal::Animal(const std::string& other)
	:type(other)
	{
		std::cout << "Animal constructor created" << std::endl;
	}
		
Animal::Animal(const Animal& other)
	:type(other.type)
	{
		std::cout << "Animal copy constructor created" << std::endl;
	}	
		
Animal& Animal::operator=(const Animal& other)
	{
		if(this != &other)
			type = other.type;
		std::cout << "Animal assignment operator copy called" << std::endl;
		return (*this);
	}

Animal::~Animal()
	{
		std::cout << "Animal destructor created" << std::endl;
	}

void	Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return(type);
}
