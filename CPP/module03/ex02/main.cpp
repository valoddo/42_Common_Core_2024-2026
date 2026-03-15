/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:55 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:30:02 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

	a = cla;
	b = bla;
	c = fla;
	cla.attack("Bla");
	bla.takeDamage(3);
	b.attack("Cla");
	cla.takeDamage(1);
	a.attack("b");
	b.beRepaired(1);
	bla.attack("Bla");
	cla.takeDamage(3);
	fla.attack("Cla");
	cla.takeDamage(2);
	fla.highFivesGuys();
	return (0);
}
