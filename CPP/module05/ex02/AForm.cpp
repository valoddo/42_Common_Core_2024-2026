/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:07:09 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/12 18:29:07 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade Too High\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade Low High");
}

const char* AForm::FormNoSigned::what() const throw()
{
	return ("Form is not signed");
}

AForm::AForm(std::string name, int required, int execute_grade)
	:name(name), required(required), execute_grade(execute_grade)
{
	if (required < 1)
		throw GradeTooHighException();
	if (required > 150)
		throw GradeTooLowException();
	if (execute_grade < 1)
		throw GradeTooHighException();
	if (execute_grade > 150)
		throw GradeTooLowException();
	sign = false;
	std::cout << "AForm constructor created" << std::endl;
}
		
AForm::AForm(const AForm& other)
	:name(other.name), sign(other.sign), required(other.required), execute_grade(other.execute_grade)
{
	std::cout << "AForm copy constructor created" << std::endl;
}

AForm& AForm::operator= (const AForm& other)
{
	if (this != &other)
		sign = other.sign;
	std::cout << "AForm assignment operator created" << std::endl;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor created" << std::endl;
}

const std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSign() const
{
	return(sign);
}

int AForm::getRequired() const
{
	return(required);
}

int AForm::getExecute() const
{
	return(execute_grade);
}
		
void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= required)
		sign = true;
	else
		throw GradeTooLowException();
}


std::ostream& operator<< (std::ostream& os, const AForm& f)
{
	os << "AForm " << f.getName() << ", signed: " << std::boolalpha << f.getSign() << ", grade required to sign: " << f.getRequired()
		<< ", grade required to execute: " << f.getExecute();
	return (os);
}

void AForm::execute(Bureaucrat const &executor) const
{
	if(!sign)
		throw FormNoSigned();
	if(executor.getGrade() > execute_grade)
		throw GradeTooLowException();
	executeAction();
}
