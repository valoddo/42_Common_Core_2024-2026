/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:55 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/27 17:28:29 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	cault;
	ScavTrap	sault;
	ClapTrap	cla("Cla");
	ScavTrap	bla("Bla");
	ClapTrap	a(cault);
	ScavTrap	b(sault);

	a = cla;
	b = bla;
	cla.attack("Bla");
	bla.takeDamage(3);
	b.attack("Cla");
	cla.takeDamage(8);
	a.attack("b");
	b.guardGate();
	b.beRepaired(1);
	bla.attack("Cla");
	cla.takeDamage(3);
	return (0);
}
