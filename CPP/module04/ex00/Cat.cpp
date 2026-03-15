/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 20:01:53 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/03 21:48:52 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	type = "🐱 Cat";
	std::cout << MAGENTA << "Cat default constructor called" << RESET << std::endl;
}
Cat::Cat(const std::string other) : Animal(other)
{
	type = "🐱 Cat";
	std::cout << MAGENTA << "Cat constructor created" << RESET << std::endl;
}
		
Cat::Cat(const Cat& other) : Animal(other)
{
	type = other.type;
	std::cout << MAGENTA << "Cat copy constructor created" << RESET << std::endl;
}
		
Cat& Cat::operator=(const Cat& other)
{
	if(this != &other)
		this->type = other.type;
	std::cout << "Cat assignment operator copy called" << std::endl;
	return(*this);
}

Cat::~Cat()
{
	std::cout << RED << "Cat destructor created" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MIAO" << std::endl;
}
