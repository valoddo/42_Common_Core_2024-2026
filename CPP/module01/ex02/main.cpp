/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:11:12 by marvin            #+#    #+#             */
/*   Updated: 2025/11/13 20:11:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "• Memory addresses:" << std::endl;
	std::cout << "Address of string:      " << &brain << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	std::cout << "\n• Values:" << std::endl;
	std::cout << "Value of string:         " << brain << std::endl;
	std::cout << "Value pointed by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of stringREF:   " << stringREF << std::endl;
	return (0);
}
