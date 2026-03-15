/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 19:48:19 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:18:13 by vloddo           ###   ########.fr       */
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

int		Fixed::getRawBits()	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(number);
}

	
void	Fixed::setRawBits(int const raw)
{
	number = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return (os);
}


bool	Fixed::operator>(const Fixed& other) const
{
	return (this->number > other.number);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->number < other.number);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->number >= other.number);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->number <= other.number);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->number == other.number);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->number != other.number);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed tmp;
	tmp.number = this->number + other.number;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed tmp;
	tmp.number = this->number - other.number;
	return (tmp);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed tmp;
	long long mul = (long long)this->number * (long long)other.number;
	tmp.number = (int)(mul >> this->fractional);
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed tmp;
	long long div = ((long long)this->number << this->fractional);
	tmp.number = (int)(div / other.number);
	return (tmp);
}

Fixed& Fixed::operator++()
{
	this->number++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->number++;
	return (tmp);
}

Fixed& Fixed::operator--()
{
	this->number--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->number--;
	return (tmp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.number < b.number)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.number < b.number)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.number > b.number)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.number > b.number)
		return (a);
	return (b);
}
