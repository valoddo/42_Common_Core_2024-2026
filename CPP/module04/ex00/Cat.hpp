/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:57:46 by vloddo            #+#    #+#             */
/*   Updated: 2025/12/01 15:56:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string other);
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();
		void	makeSound() const;
};

#endif