/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:13:36 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/16 17:05:23 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string Nickname;
		std::string PhoneNumber;
		std::string DarkestSecret;
	public:
		Contact();
		Contact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNumber, std::string DarkestSecret);
		~Contact();
		void SetFirstName(const std::string& input);
		void SetLastName(const std::string& input);
		void SetNickname(const std::string& input);
		void SetPhoneNumber(const std::string& input);
		void SetDarkestSecret(const std::string& input);
		std::string GetFirstName()const;
		std::string GetLastName()const;
		std::string GetNickname()const;
		std::string GetPhoneNumber()const;
		std::string GetDarkestSecret()const;
};

#endif
