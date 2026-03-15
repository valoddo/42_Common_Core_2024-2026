/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:21:48 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/14 12:49:28 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string input;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for(int i = 1; i < argc; i++)
		{
			input = argv[i];
			int len = input.length();
			for (int j = 0; j < len; j++)
				std::cout << (char)(toupper(input[j]));
		}
	}
	std::cout << std::endl;
	return (0);
}
