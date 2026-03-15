/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:57:46 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/01 15:56:39 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string other);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
		void	makeSound() const;
};

#endif