/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:26:51 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/18 18:09:44 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanB
{
	private:
	std::string	name;
	Weapon		*weapon;
	public:
	HumanB(const std::string& name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon& weapon);
};

#endif