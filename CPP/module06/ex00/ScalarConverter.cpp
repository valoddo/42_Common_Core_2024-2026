/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:49:47 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/26 14:15:29 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void		charConvert(std::string param)
{
	std::cout << "char: " << param[0] << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(param[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(param[0]) << std::endl;
}

static void		intConvert(std::string param)
{
	int	n = atoi(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

static void		floatConvert(std::string param)
{
	float	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << n << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(n) << std::endl;
}

static void		doubleConvert(std::string param)
{
	double	n = atof(param.c_str());

	if (n < 0 || n > 127)
		std::cout << "char: impossible" << std::endl;
	else if (n < 32 || n == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << n << std::endl;
}

static void		minInfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

static void		maxInfConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

static void		nanConvert()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

void	ScalarConverter::convert(std::string param)
{
	if (std::isprint(param[0]) && !std::isdigit(param[0]))
	{
		if (param.length() == 1)
			charConvert(param);
		else if (param == "-inf" || param == "-inff")
			minInfConvert();
		else if (param == "+inf" || param == "+inff")
			maxInfConvert();
		else if (param == "nan" || param == "nanf")
			nanConvert();
		else
			nanConvert();
	}
	else if (param[param.length() - 1] == 'f')
	{
		long unsigned int	i = 0;
		while (i < param.length() - 1 && (std::isdigit(param[i]) || param[i] == '.'))
			i++;
		if (i == param.length() - 1)
			floatConvert(param);
		else
			nanConvert();
	}
	else if (param.find('.') != std::string::npos) // npos è una costante statica definita dentro la classe std::string
	{
		long unsigned int	i = 0;
		while (std::isdigit(param[i]) || param[i] == '.')
			i++;
		if (i == param.length())
			doubleConvert(param);
		else
			nanConvert();
	}
	else if (std::isdigit(param[0]))
	{
		long unsigned int	i = 0;
		while (std::isdigit(param[i]))
			i++;
		if (i == param.length())
			intConvert(param);
		else
			nanConvert();
	}
	else
		nanConvert();
}
