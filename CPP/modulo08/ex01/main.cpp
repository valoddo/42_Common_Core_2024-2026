/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:15:27 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/05 11:07:55 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try 
	{
        Span sp(10);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// std::vector<int> v;
		// v.push_back(20);
		// v.push_back(30);
		// v.push_back(40);
		// sp.addMultiNumber(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
    }
    catch (const std::exception& e)
	{
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

/* int main()
{
	Span sp = Span(1);
	
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	std::vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	sp.addMultiNumber(v.begin(), v.end());
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	return 0;
} */