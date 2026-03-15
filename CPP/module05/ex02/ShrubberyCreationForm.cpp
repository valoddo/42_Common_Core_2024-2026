/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 11:17:41 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/19 16:54:23 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
	{
		std::cout << "ShrubberyCreationForm constructor created" << std::endl;
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other), target(other.target)
	{
		std::cout << "ShrubberyCreationForm copy constructor created" << std::endl;
	}
	
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	std::cout << "ShrubberyCreationForm assignment operator created" << std::endl;
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor created" << std::endl;
}
		
void ShrubberyCreationForm::executeAction() const
{
    std::string filename = target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
    if (!ofs)
    {
        std::cerr << "Error: could not create file " << filename << std::endl;
        return;
    }
    ofs << "   ###   \n";
    ofs << "  #o###  \n";
    ofs << " #####o# \n";
    ofs << " #o#\\#|# \n";
    ofs << " ###\\|/# \n";
    ofs << "   |||   \n";
    ofs << "   |||   \n";
    ofs << "   |||   \n";

    ofs.close();
}
