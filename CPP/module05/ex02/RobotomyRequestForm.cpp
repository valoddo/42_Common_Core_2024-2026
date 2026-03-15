/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:18:59 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:54:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	: AForm("RobotomyRequestForm", 72, 45), target(target)
	{
    	std::srand(std::time(0));
		std::cout << "RobotomyRequestForm construction created" << std::endl;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target(other.target)
	{
		std::cout << "RobotomyRequestForm copy constructor created" << std::endl;
	}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "RobotomyRequestForm assignment operator created" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor created" << std::endl;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "*Drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << target << std::endl;
}
