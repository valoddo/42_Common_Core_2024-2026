/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:48:19 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:10:00 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& numb)
{
	number = numb.number;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->number = other.number;
	}
	return(*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits()	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(number);
}

	
void	Fixed::setRawBits(int const raw)
{
	number = raw;
}