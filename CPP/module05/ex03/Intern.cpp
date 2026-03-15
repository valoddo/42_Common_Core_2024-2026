/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:09:19 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:54:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout <<"Intern default constructor created" << std::endl;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout <<"Intern copy constructor created" << std::endl;
}

Intern& Intern::operator= (const Intern& other)
{
	(void)other;
	std::cout <<"Intern assignment operator created" << std::endl;
	return(*this);
}

Intern::~Intern()
{
	std::cout <<"Intern destructor created" << std::endl;
}

static AForm* createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}
static AForm* createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}
static AForm* createPresidential(std::string target)
{ 
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	std::string formNames[3] = {"shrubbery request", "robotomy request", "presidential request"};
	AForm* (*formCreators[3])(std::string) = {&createShrubbery, &createRobotomy, &createPresidential};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (formCreators[i](target));
		}
	}
	std::cerr << "Error: form " << name << " does not exist" << std::endl;
	return (NULL);
}
