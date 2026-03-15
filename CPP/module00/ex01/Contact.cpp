/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:58:03 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/16 17:15:35 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){};

Contact::Contact(std::string a, std::string b, std::string c, std::string d, std::string e)
	: FirstName(a), LastName(b), Nickname(c), PhoneNumber(d), DarkestSecret(e){}

Contact::~Contact(){}

void Contact::SetFirstName(const std::string& input)
{
	FirstName = input;
}

void Contact::SetLastName(const std::string& input)
{
	LastName = input;
}

void Contact::SetNickname(const std::string& input)
{
	Nickname = input;
}

void Contact::SetPhoneNumber(const std::string& input)
{
	PhoneNumber = input;
}

void Contact::SetDarkestSecret(const std::string& input)
{
	DarkestSecret = input;
}


std::string Contact::GetFirstName()const
{
	return(FirstName);
}

std::string Contact::GetLastName()const
{
	return(LastName);
}

std::string Contact::GetNickname()const
{
	return(Nickname);
}

std::string Contact::GetPhoneNumber()const
{
	return(PhoneNumber);
}

std::string Contact::GetDarkestSecret()const
{
	return(DarkestSecret);
}
