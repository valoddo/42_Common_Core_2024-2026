/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:37:59 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/16 12:56:46 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const	std::string name;
		int		grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator= (const Bureaucrat& other);
		~Bureaucrat();
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual	const char* what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual	const char* what() const throw();
		};
		const std::string getName() const;
		int	getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signAForm(AForm& f);
		void executeForm(AForm const & form) const;
		
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif