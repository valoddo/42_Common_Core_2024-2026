/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:53:25 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:53:50 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> // per srand, rand
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    

    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << std::endl;
        alice.signAForm(shrub);
        alice.executeForm(shrub);

        // ------------------- RobotomyRequestForm -------------------
        RobotomyRequestForm robo("Bender");
        std::cout << robo << std::endl;
        alice.signAForm(robo);
        alice.executeForm(robo);
        alice.executeForm(robo);
        // ------------------- PresidentialPardonForm -------------------
        PresidentialPardonForm pardon("Ford");
        std::cout << pardon << std::endl;
        alice.signAForm(pardon);
        alice.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

