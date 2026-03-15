/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:35:33 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/16 17:35:18 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook()
	: i(0){};

PhoneBook::~PhoneBook(){};

void PhoneBook::addContact()
{
	std::string input;
	
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Errore: il campo non può essere lasciato vuoto!\n";
		std::cout << "First Name: ";
		std::getline(std::cin, input);
	}
	contact[i % 8].SetFirstName(input);
	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Errore: il campo non può essere lasciato vuoto!\n";
		std::cout << "Last Name: ";
		std::getline(std::cin, input);
	}
	contact[i % 8].SetLastName(input);
	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Errore: il campo non può essere lasciato vuoto!\n";
		std::cout << "Nickame: ";
		std::getline(std::cin, input);
	}
	contact[i % 8].SetNickname(input);
	std::cout << "Phone Number: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Errore: il campo non può essere lasciato vuoto!\n";
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
	}
	contact[i % 8].SetPhoneNumber(input);
	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	while (input.empty())
	{
		std::cout << "Errore: il campo non può essere lasciato vuoto!\n";
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
	}
	contact[i % 8].SetDarkestSecret(input);
	i++;
}

std::string	formatColumn(const std::string &str)
{
	if (str.length() > 10)
	{
		std::string s = str.substr(0, 9);
		s += '.';
		return s;
	}
	return (str);
}

void	PhoneBook::displayContacts() const
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (contact[i].GetFirstName().empty())
			continue;
		std::cout << std::setw(10) << i << "|"
				<< std::setw(10) << formatColumn(contact[i].GetFirstName()) << "|"
				<< std::setw(10) << formatColumn(contact[i].GetLastName()) << "|"
				<< std::setw(10) << formatColumn(contact[i].GetNickname()) << "|" << std::endl;
	}
}

bool isNumber(const std::string &s)
{
    if (s.empty())
        return false;

    for (std::string::size_type i = 0; i < s.size(); i++)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

void	PhoneBook::searchContact() const
{
	std::string	input;
	int	j;

	displayContacts();
	std::cout << "Inserisci l'indice del contatto che vuoi visualizzare ";
	std::getline(std::cin, input);
	if (!isNumber(input))
    {
        std::cout << "Errore: devi inserire un numero!" << std::endl;
        return;
    }
	j = std::strtol(input.c_str(), NULL,10);
	if (j < 0 || j >= 8 || contact[j].GetFirstName().empty())
	{
		std::cout << "Indice non valido o contatto non esistente" << std::endl;
		return;
	}
	std::cout << "First Name: " << contact[j].GetFirstName() << std::endl;
	std::cout << "Last Name: " << contact[j].GetLastName() << std::endl;
	std::cout << "Nickname: " << contact[j].GetNickname() << std::endl;
	std::cout << "Phone Number: " << contact[j].GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact[j].GetDarkestSecret() << std::endl;
}
