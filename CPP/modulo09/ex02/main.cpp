/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 17:22:48 by marvin            #+#    #+#             */
/*   Updated: 2026/02/21 17:22:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int main(int argc, char** argv)
{
    double timeVector;
    double timeDeque;

    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
        return 1;
    }
    try
    {
        PmergeMe pm(argv);

        // Ordina vector e misura tempo
        std::vector<int> vecCopy = pm.getVector();
        std::clock_t start = std::clock();
        pm.sortVector(vecCopy);
        std::clock_t end = std::clock();
        timeVector = double(end - start) / CLOCKS_PER_SEC;

        // Ordina deque e misura tempo
        std::deque<int> deqCopy = pm.getDeque();
        start = std::clock();
        pm.sortDeque(deqCopy);
        end = std::clock();
        timeDeque = double(end - start) / CLOCKS_PER_SEC;

        // Stampa sequenza ordinata (vector)
        std::cout << "Vect Sort:  ";
        for (size_t i = 0; i < vecCopy.size(); ++i)
            std::cout << vecCopy[i] << " ";
        std::cout << std::endl;

        // Stampa sequenza ordinata (deque)
        std::cout << "Deque Sort:  ";
        for (size_t i = 0; i < deqCopy.size(); ++i)
            std::cout << deqCopy[i] << " ";
        std::cout << std::endl;

        // Stampa tempi
        std::cout << "Time to process a range of " << vecCopy.size()
                  << " elements with Vector: "
                  << std::fixed << std::setprecision(6)
                  << timeVector << " sec" << std::endl;

        std::cout << "Time to process a range of " << deqCopy.size()
                  << " elements with Deque: "
                  << std::fixed << std::setprecision(6)
                  << timeDeque << " sec" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}