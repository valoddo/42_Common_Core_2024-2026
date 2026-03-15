/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:10:17 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/27 16:48:52 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./btc input.txt" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange btc;   // carica automaticamente data.csv
        btc.output(argv[1]);   // processa file input
    }
    catch (std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
