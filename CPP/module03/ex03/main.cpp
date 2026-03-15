/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:55 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:34:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{

	ClapTrap	cault;
	ScavTrap	sault;
	FragTrap	fault;
	ClapTrap	cla("Cla");
	ScavTrap	bla("Bla");
	FragTrap	fla("Fla");
	ClapTrap	a(cault);
	ScavTrap	b(sault);
	FragTrap	c(fault);
	DiamondTrap d1;
	DiamondTrap d2("Pippo");
	DiamondTrap d3(d2);

	a = cla;
	b = bla;
	c = fla;
	cla.attack("Bla");
	bla.takeDamage(3);
	b.attack("Cla");
	cla.takeDamage(1);
	a.attack("b");
	b.beRepaired(1);
	bla.attack("kiko");
	cla.takeDamage(3);
	fla.attack("Cla");
	cla.takeDamage(2);
	fla.highFivesGuys();

	d1 = d2;

	d2.attack("target");
	d2.highFivesGuys();
	d2.guardGate();
	d2.whoAmI();

	d3.attack("enemy");
	d3.whoAmI();
	return (0);
}

