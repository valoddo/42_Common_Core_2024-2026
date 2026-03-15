/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:34:05 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/02 20:26:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal()
	:type("AAnimal")
	{
		std::cout << "AAnimal default constructor called" << std::endl;
	}
	
AAnimal::AAnimal(const std::string other)
	:type(other)
	{
		std::cout << "AAnimal constructor called" << std::endl;
	}
	
AAnimal::AAnimal(const AAnimal& other)
	:type(other.type)
	{
		std::cout << "AAnimal copy constructor called" << std::endl;
	}	

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "AAnimal assignment operator copy called" << std::endl;
	return(*this);	
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return(type);
}