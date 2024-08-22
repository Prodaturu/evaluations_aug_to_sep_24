/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:47:02 by bwerner           #+#    #+#             */
/*   Updated: 2024/08/18 14:06:54 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("nameless"), health(10), energy(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " (" << health << " HP) constructed by default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), health(10), energy(10), attack_damage(0)
{
	std::cout << "ClapTrap " << name << " (" << health << " HP) constructed by name constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), health(other.health), energy(other.energy), attack_damage(other.attack_damage)
{
	
	std::cout << "ClapTrap " << name << " (" << health << " HP) constructed by copy constructor" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called on ClapTrap " << name << std::endl;
}


ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Assignment operator called on ClapTrap " << name << std::endl;

	if (this == &other)
		return (*this);
	name = other.name;
	health = other.health;
	energy = other.energy;
	attack_damage = other.attack_damage;
	return (*this);
}


void	ClapTrap::attack(const std::string& target)
{
	std::cout << name << " (" << health << " HP) ";
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " (" << health << " HP) takes " << amount << " damage and now has ";
	if (amount > health)
		health = 0;
	else
		health -= amount;
	std::cout << health << " hitpoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << name << " (" << health << " HP) ";
	if (!health)
		std::cout << "can not repair itself because it has no hitpoints";
	else if (!energy)
		std::cout << "can not repair itself because it has no energy";
	else
	{
		energy--;
		health += amount;
		std::cout << "repairs itself for " << amount << " hitpoints and now has " << health << " hitpoints";
	}
	std::cout << std::endl;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	attack_damage = amount;
	std::cout << name << " (" << health << " HP) now has " << attack_damage << " attack damage" << std::endl;
}
