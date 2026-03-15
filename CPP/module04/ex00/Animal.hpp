/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:32:44 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/04 19:18:24 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include <string>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const std::string& other);
		Animal(const Animal& other);
		Animal&			operator=(const Animal& other);
		virtual ~Animal();
		virtual void	makeSound() const;
		std::string		getType() const;
};


#endif