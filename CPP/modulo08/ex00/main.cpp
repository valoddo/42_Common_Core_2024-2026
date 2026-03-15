/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:15:27 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/05 10:53:43 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main()
{
    std::vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
    
	if (easyfind(v, 4))
        std::cout << "Finded!\n";
    else
        std::cout << "Try again.\n";
}
