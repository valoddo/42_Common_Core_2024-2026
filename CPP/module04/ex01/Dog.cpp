/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:06:28 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/04 19:19:39 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
	type = "🐶 Dog";
	brain = new Brain();
	for (int i = 0; i < 100; i++)
	{
		brain->setIdea(i, "🐶💡 Dog Idea");
	}
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal (other)
{
	brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}
		
Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	std::cout << "Dog assignment operator copy called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "BAU" << std::endl;
}

void Dog::printIdea(int index) const
{
	std::cout << YELLOW << brain->getIdea(index) << RESET << std::endl;
}