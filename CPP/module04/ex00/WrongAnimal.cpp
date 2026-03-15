/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:28:00 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/01 15:42:57 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "";
	std::cout << "WrongAnimal default costructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string other)
	: type(other)
{
	std::cout << "WrongAnimal costructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	: type(other.type)
{
	std::cout << "WrongAnimal copy costructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "WrongAnimal assignment operator copy called" << std::endl;
	return(*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return(type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
