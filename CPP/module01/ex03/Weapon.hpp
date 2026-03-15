/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:57:36 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/18 18:10:09 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <iostream>
#include <string>

class	Weapon
{
	private:
	std::string	type;
	public:
	Weapon();
	Weapon(const std::string& input);
	~Weapon();
	const std::string&	getType()const;
	void	setType(const std::string& type);
};

#endif