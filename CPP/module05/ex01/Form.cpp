/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:07:09 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:49:01 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}

const char* Form::FormNoSigned::what() const throw()
{
	return ("Form is not signed");
}

Form::Form(std::string name, int required, int execute)
	:name(name), required(required), execute(execute)
{
	if (required < 1)
		throw GradeTooHighException();
	if (required > 150)
		throw GradeTooLowException();
	if (execute < 1)
		throw GradeTooHighException();
	if (execute > 150)
		throw GradeTooLowException();
	sign = false;
	std::cout << "Form constructor created" << std::endl;
}
		
Form::Form(const Form& other)
	:name(other.name), sign(other.sign), required(other.required), execute(other.execute)
{
	std::cout << "Form copy constructor created" << std::endl;
}

Form& Form::operator= (const Form& other)
{
	if (this != &other)
		sign = other.sign;
	std::cout << "Form assignment operator created" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor created" << std::endl;
}

const std::string Form::getName() const
{
	return (name);
}

bool Form::getSign() const
{
	return(sign);
}

int Form::getRequired() const
{
	return(required);
}

int Form::getExecute() const
{
	return(execute);
}
		
void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= required)
		sign = true;
	else
		throw GradeTooLowException();
}


std::ostream& operator<< (std::ostream& os, const Form& f)
{
    os << "Form " << f.getName() << ", signed: " << std::boolalpha << f.getSign() << ", grade required to sign: " << f.getRequired()
       << ", grade required to execute: " << f.getExecute();
	return (os);
}
