/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:07:29 by vloddo            #+#    #+#             */
/*   Updated: 2025/11/24 23:07:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	:name(""), hitPoints(100), energyPoints(50), attackDamage(20)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& fname)
		:name(fname), hitPoints(100), energyPoints(50), attackDamage(20)
		{
			std::cout << "ClapTrap constructor called" << std::endl;
		}
		
ClapTrap::ClapTrap(const ClapTrap& other)
		:name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
		{
			std::cout << "ClapTrap copy constructor called" << std::endl;
		}
		
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if(this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy for attack!" << std::endl;
		return ;
	} 
	if(hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no life for attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " <<  attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > hitPoints)
		hitPoints = 0;
	else 
		hitPoints = hitPoints - amount;
	if(hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no life left!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has taken " << amount << " points of damage and has " << hitPoints << " of life!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy for repair!" << std::endl;
		return ;
	}
	if(hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no life for repair!" << std::endl;
		return ;
	}
	energyPoints--;
	hitPoints = hitPoints + amount;
	if (hitPoints >= 10)
		hitPoints = 10;
	std::cout << "ClapTrap " << name << " repairs itself, recovering " << amount << " hit points and has " << hitPoints << " of life!" << std::endl;
}
