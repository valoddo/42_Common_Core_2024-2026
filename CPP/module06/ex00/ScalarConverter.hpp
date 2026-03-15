/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 17:49:50 by vloddo            #+#    #+#             */
/*   Updated: 2026/01/26 13:53:41 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>
#include <cstdlib>   // atoi, atof
#include <climits>    // numeric_limits
#include <cctype>    // isprint isdigit
#include <cmath>     // isnan, isinf
#include <iomanip>   // per std::setprecision e std::fixed
#include <limits.h>
#include <float.h>



class	ScalarConverter
{
	private:
		ScalarConverter(); // questo rende la classe non istanziabile
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator= (const ScalarConverter& other);
		virtual ~ScalarConverter();
	public:
	static void convert(std::string param);
};

#endif