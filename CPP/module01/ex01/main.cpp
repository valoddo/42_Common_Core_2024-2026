/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:04:35 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/18 18:06:59 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie*	horde;

	if (N <= 0)
		return (NULL);
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}

int	main()
{
	std::string	input;
	Zombie*		zombiehorde;
	int			N;

	std::cout << "Quanti zombie vuoi nell’orda? ";
	std::cin >> N;
	std::cin.ignore();
	std::cout << "Nome degli zombie dell’orda: ";
	std::getline(std::cin, input);
	zombiehorde = zombieHorde(N, input);
	for (int i = 0; i < N; i++)
		zombiehorde[i].announce();
	delete[] zombiehorde;
	return (0);
}
