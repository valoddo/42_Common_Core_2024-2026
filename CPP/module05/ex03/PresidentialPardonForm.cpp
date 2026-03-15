/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:15:00 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/16 12:31:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:AForm("PresidentialPardonForm", 25, 5), target(target)
	{
		std::cout << "PresidentialPardonForm constructor created" << std::endl;
	}
	
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other), target(other.target)
	{
		std::cout << "PresidentialPardonForm copy constructor created" << std::endl;
	}
	
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "PresidentialPardonForm assignment operator created" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor created" << std::endl;
}

void PresidentialPardonForm::executeAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
