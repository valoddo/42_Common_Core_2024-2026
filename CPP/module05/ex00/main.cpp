/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:53:25 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:48:32 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat b1("Alice", 0);
    }
    catch (Bureaucrat::GradeTooHighException &e)
	{
        std::cout << "Errore: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
	{
        std::cout << "Errore: " << e.what() << std::endl;
    }

    try
	{
        Bureaucrat b2("Bob", 149);
        b2.incrementGrade();
    }
    catch (std::exception &e)
	{
        std::cout << "Errore durante l’increment: " << e.what() << std::endl;
    }
    return (0);
}
