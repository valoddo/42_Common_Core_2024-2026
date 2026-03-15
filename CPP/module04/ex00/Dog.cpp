/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:01:53 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/03 21:49:14 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "🐶 Dog";
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
}
Dog::Dog(const std::string other) : Animal(other)
{
	type = "🐶 Dog";
	std::cout << BLUE << "Dog constructor created" << RESET << std::endl;
}
		
Dog::Dog(const Dog& other) : Animal(other)
{
	type = other.type;
	std::cout << "Dog copy constructor created" << std::endl;
}
		
Dog& Dog::operator=(const Dog& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "Dog assignment operator copy called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor created" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "BAU" << std::endl;
}
