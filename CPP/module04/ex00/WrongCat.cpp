/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:00:12 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/01 16:07:24 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	type = "WrongCat";
	std::cout << "WrongCat default costructor called" << std::endl;
}

WrongCat::WrongCat(const std::string other) : WrongAnimal(other)
{
	type = "WrongCat";
	std::cout << "WrongCat costructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	this->type = "Cat";
	std::cout << "WrongCat costructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "WrongCat assignment operator copy called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor created" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}