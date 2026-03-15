/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:19:29 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/14 17:45:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(const std::string& input)
		:type(input){}

Weapon::~Weapon(){}

const std::string&	Weapon::getType()const
{
	return(type);
}

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}
