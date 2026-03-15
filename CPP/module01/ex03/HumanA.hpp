/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.pp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:26:00 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/14 16:36:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP
#include <iostream>
#include <string>
#include "Weapon.hpp"

class	HumanA
{
	private:
	std::string	name;
	Weapon		&weapon;
	public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
	void	attack();
};

#endif