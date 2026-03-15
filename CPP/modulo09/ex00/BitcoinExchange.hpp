/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:10:47 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/18 16:14:21 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
	private:
		std::map <std::string, double> database;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& o);
		BitcoinExchange& operator=(const BitcoinExchange& o);
		~BitcoinExchange();
		
		void loadDatabase(const std::string& filecsv);
		void	output(const std::string& inputfile);
		double getExchangeRate(const std::string& date) const;
};

#endif
