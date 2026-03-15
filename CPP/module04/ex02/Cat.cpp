/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:45:55 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/04 19:20:35 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	type = "🐱 Cat";
	brain = new Brain();
    // riempio 100 idee direttamente nel costruttore
	for (int i = 0; i < 100; i++)
	{
		brain->setIdea(i, "🐱💡 Cat Idea");
	}
	std::cout << MAGENTA << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : AAnimal (other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}
		
Cat& Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->type = other.type;
		*this->brain = *other.brain;
	}
	std::cout << "Cat assignment operator copy called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "MIAO" << std::endl;
}

void Cat::printIdea(int index) const
{
	std::cout << GREEN << brain->getIdea(index) << RESET << std::endl;
}