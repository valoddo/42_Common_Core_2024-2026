/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:16:40 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/25 21:31:05 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Default_clap_name"),
	ScavTrap(),
	FragTrap()
{
	name = "";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name)
{
	this->name = name;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other.ClapTrap::name),
	ScavTrap(other),
	FragTrap(other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if(this != &other)
	{
		ClapTrap::operator=(other);
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "DiamondTrap operator assignment called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;	
}

void DiamondTrap::attack(const std::string &target)
{
    if(ClapTrap::hitPoints == 0)
    {
        std::cout << "DioamondTrap " << name << " is dead and cannot attack.\n";
        return;
    }
    if(ClapTrap:: energyPoints == 0)
    {
        std::cout << "DioamondTrap " << name << " has no energy to attack.\n";
        return;
    }
    std::cout << "DioamondTrap " << name << " attacks " << target << ", causing " << ClapTrap:: attackDamage << " damage!\n";
    --ClapTrap::energyPoints;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap named: " << name << " and Claptrap named: " << ClapTrap::name << std::endl;
}
