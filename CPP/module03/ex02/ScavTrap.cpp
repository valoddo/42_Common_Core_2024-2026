/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 09:21:46 by marvin            #+#    #+#             */
/*   Updated: 2025/11/24 09:21:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap () : ClapTrap()
{
	this->name = "";
	hitPoints = 100; 
	energyPoints = 50; 
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	this->name = name;
	hitPoints = 100; 
	energyPoints = 50; 
	attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	name = other.name;
	hitPoints = other.hitPoints;
	energyPoints = other.energyPoints;
	attackDamage = other.attackDamage;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if(energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " has no energy for attack!" << std::endl;
		return ;
	} 
	if(hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " has no life for attack!" << std::endl;
		return ;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " <<  attackDamage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is in Gate mode" << std::endl;
}
