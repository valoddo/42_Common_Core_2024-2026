/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:10:44 by vloddo            #+#    #+#             */
/*   Updated: 2026/02/27 17:00:26 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){this->loadDatabase("data.csv");}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& o)
{
	database = o.database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& o)
{
	if(this != &o)
		database = o.database;
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {}
		
void BitcoinExchange::loadDatabase(const std::string& filecsv)
{
	std::string line;
	std::string date;
	double rate;
	size_t pos;
	std::ifstream infile(filecsv.c_str());
	if (!infile)
	{
		std::cerr << "Error: can not open file" << std:: endl;
		return;
	}
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;
		pos = line.find(',');
		if (pos == std::string::npos )
			return;
		date = line.substr(0, pos);
		rate = atof(line.substr(pos + 1).c_str());
		database.insert(std::make_pair(date, rate));
	}
}
		
void BitcoinExchange::output(const std::string& inputfile)
{
	std::string line;
	std::string date;
	double value;
	double rate;
	size_t pos;
	std::map<std::string, double>::iterator it;
	
	std::ifstream infile(inputfile.c_str());
	if(inputfile.find(".txt")== std::string::npos)
	{
		std::cerr << "Error: insert file '.txt'" << std:: endl;
		return;
	}
	if (!infile)
	{
		std::cerr << "Error: could not open file" << std:: endl;
		return;
	}
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		if (line.empty())
			continue;
		pos = line.find('|');
		if (pos == std::string::npos )
		{
			std::cout << "Error : bad input => "<< line << std:: endl;
			continue;
		}
		date = line.substr(0, pos);
		value = atof(line.substr(pos + 2).c_str());
		if (value < 0 || value >  2147483647)
		{
			if (value < 0)
				std::cout << "Error: not a positive number." << std:: endl;
			else
				std::cout << "Error: too large a number." << std:: endl;	
			continue;
		}
		try
		{
			rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << value * rate << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}	
	}
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    if (database.empty())
        throw std::runtime_error("database is empty");
    std::map<std::string, double>::const_iterator it = database.lower_bound(date);

    // Caso 1: data esatta
    if (it != database.end() && it->first == date)
        return it->second;
    // Caso 2: nessuna data precedente disponibile
    if (it == database.begin())
        throw std::runtime_error("Error: no exchange rate available for this date.");
    // Caso 3: prendi la data precedente
    --it;
    return it->second;
}

