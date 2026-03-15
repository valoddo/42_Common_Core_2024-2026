/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:40:09 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:11:55 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class	Fixed
{
	private:
	int					number;
	static const int	fractional = 8;
	public:
	Fixed();
	Fixed(const Fixed& numb);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	Fixed(const int numb);
	Fixed(const float numb);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif