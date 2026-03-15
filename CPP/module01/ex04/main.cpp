/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:53:59 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/19 12:38:09 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

std::string	ft_replace(const std::string &line, const std::string &s1, const std::string &s2)
{
	std::string	result;
	size_t		pos;

	result = line;
	pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result = result.substr(0, pos) + s2 + result.substr(pos + s1.length());
		pos += s2.length();
	}
	return (result);
}

int	main(int argc, char** argv)
{
	std::string	file;
	std::string	repfile;
	std::string	line;
	std::string	s1;
	std::string	s2;
	
	if(argc != 4)
	{
		std::cerr << "Usage: <a.out> <file.txt> <s1> <s2>" << std::endl;
		return (1);
	}
	file = argv[1];
	s1 = argv[2];
	s2 = argv[3];	
	if (s1.empty())
	{
		std::cerr << "Error: insert a valid name for s1" << std::endl;
		return (1);
	}
	std::ifstream infile(file.c_str());
	if (!infile)
	{
		std::cerr << "Error: can not open file" << std:: endl;
		return (1);
	}
	repfile = file + ".replace";
	std::ofstream outfile(repfile.c_str());
	if (!outfile)
	{
		std::cerr << "Error: can not create replace file" << std:: endl;
		return (1);
	}
	while (std::getline(infile, line))
	{
		std::string newLine = ft_replace(line, s1, s2);
		outfile << newLine << std::endl;
	}
	return (0);	
}
