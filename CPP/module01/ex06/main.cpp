/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 17:12:13 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/19 12:33:28 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HarlFilter.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int j = -1;

	if (argc != 2)
	{
		std::cout << "Usage: <a.out> <complain>" << std::endl;
		return (1);
	}
	std::string level = argv[1];
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			j = i;
			break;
		}
	}
	switch (j)
	{
	case 0:
		std::cout << "[ DEBUG ]\n";
		harl.debug();
	case 1:
		std::cout << "[ INFO ]\n";
		harl.info();
	case 2:
		std::cout << "[ WARNING ]\n";
		harl.warning();
	case 3:
		std::cout << "[ ERROR ]\n";
		harl.error();
		break;
	default:
		std::cout << "[ Don't you have a complain to do? ]\n";
	}
	return (0);
}
