/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:04:35 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/19 12:11:12 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zombienew;

	zombienew = new Zombie(name);
	return (zombienew);
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

int main()
{
	std::string input;
	Zombie *zombienew;

	std::cout << "Inserisci il nome dello zombie (heap): ";
	std::getline(std::cin, input);
	zombienew = newZombie(input);
	zombienew->announce();
	delete zombienew;
	std::cout << "------------------------" << std::endl;
	std::cout << "Inserisci il nome dello zombie (stack): ";
	std::getline(std::cin, input);
	randomChump(input);
	return (0);
}
