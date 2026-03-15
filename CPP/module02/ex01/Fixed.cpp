/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:48:19 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:11:28 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	:number(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& numb)
	:number(numb.number)
{
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

Fixed::Fixed(const int numb)
	:number(numb << fractional)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float numb)
	:number(roundf(numb * (1 << fractional)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	float number2 = static_cast<float>(number);
	return (number2/(1 << fractional));
}


int	Fixed::toInt( void ) const
{
	return (number >> fractional); 
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}