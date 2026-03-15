/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:13:33 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/16 17:05:39 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	command;
	bool		running;
	
	running = true;
	std::cout << "Comandi disponibili: ADD, SEARCH, EXIT" << std::endl;
	while (running)
	{
		std::cout << "Inserisci un comando: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << "\nUscita dal programma." << std::endl;
			running = false;
		}
		else if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Chiusura del PhoneBook..." << std::endl;
			running = false;
		}
		else if (command.empty())
			running = true;
		else
			std::cout << "Comando non riconosciuto. Usa: ADD, SEARCH o EXIT." << std::endl;
	}
	return (0);
}
