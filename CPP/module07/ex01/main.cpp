/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:53:23 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/01 13:04:33 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void incrementInt(int& x)
{
    x += 1;
}

void addExclamation(std::string& s)
{
    s += "!";
}

int main()
{
    // ================== TEST ARRAY DI INT ==================
    int arrayint[] = {0, 1, 2};
    int intlen = 3;

    std::cout << "Array int originale: ";
    iter(arrayint, intlen, print); // const&
    std::cout << std::endl;

    iter(arrayint, intlen, incrementInt); // &
    
    std::cout << "Array int dopo increment: ";
    iter(arrayint, intlen, print);
    std::cout << std::endl << std::endl;

    // ================== TEST ARRAY DI STRING ==================
    std::string arraystr[] = {"hello", "world", "42"};
    int strlen = 3;

    std::cout << "Array string originale: ";
    iter(arraystr, strlen, print); // const&
    std::cout << std::endl;

    iter(arraystr, strlen, addExclamation); // &
    
    std::cout << "Array string dopo modifica: ";
    iter(arraystr, strlen, print);
    std::cout << std::endl;

    return (0);
}

