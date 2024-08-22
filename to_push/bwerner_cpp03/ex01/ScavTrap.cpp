/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:13:54 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/23 14:25:30 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap " << name << " constructed with default constructor" << std::endl;

	health = 100;
	energy = 50;
	attack_damage = 20;
	guarding = false;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " constructed with name constructor" << std::endl;

	health = 100;
	energy = 50;
	attack_damage = 20;
	guarding = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap " << name << " constructed with copy constructor" << std::endl;

	guarding = other.guarding;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Destructor called on ScavTrap " << name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Assignment operator called on ScavTrap " << name << std::endl;

	ClapTrap::operator=(other);
	guarding = other.guarding;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	std::cout << "ScavTrap " << name << " (" << health << " HP) ";
	if (!health)
		std::cout << "can not attack because it has no hitpoints";
	else if (!energy)
		std::cout << "can not attack because it has no energy";
	else
	{
		energy--;
		std::cout << "attacks " << target << ", causing " << attack_damage << " points of damage";
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " (" << health << " HP) ";
	if (!health)
		std::cout << "can not guard the Gate because it has no hitpoints";
	else
	{
		guarding = true;
		std::cout << "is now in Gate keeper mode";
	}
	std::cout << std::endl;
}
