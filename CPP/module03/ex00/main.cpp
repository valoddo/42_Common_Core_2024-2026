/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:10:55 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:28:54 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	ault;
	ClapTrap	cla("Cla");
	ClapTrap	bla("Bla");
	ClapTrap	a(ault);
	ClapTrap	b(ault);

	a = cla;
	b = bla;
	cla.attack("Bla");
	bla.takeDamage(3);
	b.attack("Cla");
	cla.takeDamage(8);
	a.attack("b");
	b.beRepaired(1);
	bla.attack("Cla");
	cla.takeDamage(3);
	return (0);
}
