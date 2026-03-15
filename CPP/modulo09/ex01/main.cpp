/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 12:52:06 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 12:52:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char** argv)
{
	Rpn expr;
	double result;
	if (argc != 2)
	{
		std::cerr << "Usage: ./<<RPN expression>>" << std::endl;
		return (1);
	}
	try
	{
		result= expr.calculate(argv[1]);
		std::cout << result << std::endl;	
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return(1);
	}
	return(0);
}