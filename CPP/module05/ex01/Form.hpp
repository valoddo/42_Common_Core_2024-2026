/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:07:13 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/16 12:59:12 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string name;
		bool	sign;
		const int	required;
		const int	execute;
	public:
		Form(std::string name, int required, int execute);
		Form(const Form& other);
		Form& operator= (const Form& other);
		~Form();
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
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif