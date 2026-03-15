/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:53:25 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:50:18 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat alice("Alice", 50);
		Bureaucrat bob("Bob", 100);
		Form taxForm("TaxForm", 75, 30);
		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);  
		std::cout << taxForm << std::endl;
		alice.signForm(taxForm);  
		std::cout << taxForm << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
		return (0);
}
