/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:07:13 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/12 18:24:47 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
		bool	sign;
		const int	required;
		const int	execute_grade;
	public:
		AForm(std::string name, int required, int execute_grade);
		AForm(const AForm& other);
		AForm& operator= (const AForm& other);
		virtual ~AForm();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class FormNoSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		const std::string getName() const;
		bool getSign() const;
		int getRequired() const;
		int getExecute() const;
		void beSigned(const Bureaucrat& b);
		virtual void executeAction() const = 0;
		void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
