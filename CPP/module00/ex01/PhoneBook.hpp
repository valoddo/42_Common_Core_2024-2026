/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:40:39 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/14 12:55:03 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact contact[8];
		int i;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact();
		void searchContact() const;
		void displayContacts() const;
};

#endif