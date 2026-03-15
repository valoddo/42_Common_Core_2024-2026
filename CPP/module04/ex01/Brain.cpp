/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:38:34 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/03 20:43:47 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Animal.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for(int i = 0; i <= 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
	if(this != &other)
	{
		for(int i = 0; i <= 100; i++)
			this->_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain copy assignment called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

std::string	Brain::getIdea(int i) const
{
	if(i >0 && i < 99)
		return(_ideas[i]);
	else
		return("");
}

void Brain::setIdea(int i, const std::string str)
{
	if(i >0 && i < 99)
		_ideas[i] = str;
}
