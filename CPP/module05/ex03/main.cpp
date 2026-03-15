/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:53:25 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:55:23 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // per srand, rand
#include <ctime>   // per time
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someIntern;
    Bureaucrat bob("Bob", 1);
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };
    for (int i = 0; i < 4; i++)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "Test form: " << formNames[i] << std::endl;
        AForm* f = someIntern.makeForm(formNames[i], "Target_X");
        if (f)
        {
            std::cout << *f << std::endl;
            bob.signAForm(*f);
            bob.executeForm(*f);
            delete f;
        }
        else
        {
            std::cout << "Form non creato" << std::endl;
        }
    }
    return 0;
}