/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:37:53 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:54:40 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade Too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade Too Low");
}
Bureaucrat::Bureaucrat(std::string name, int grade)
	:name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor created" << std::endl;
}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& other)
{
	if (this!= &other)
		grade = other.grade;
	std::cout << "Bureaucrat assignment operator created" << std::endl;
	return(*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor created" << std::endl;
}
		
const std::string Bureaucrat::getName() const
{
	return (name);
}
		
int	Bureaucrat::getGrade() const
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw GradeTooHighException();	
	grade--;
}
		
void Bureaucrat::decrementGrade()
{
	if(grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signAForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (os);
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
