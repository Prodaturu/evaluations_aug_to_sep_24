/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:08:58 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:19:33 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

void	FragTrap::initValues(void)
{
	health = 100;
	energy = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap " << this->name << " constructed with default constructor" << std::endl;

	initValues();
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->name << " constructed with name constructor" << std::endl;

	initValues();
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << this->name << " constructed with copy constructor" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Destructor called on FragTrap " << name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Assignment operator called on FragTrap " << name << std::endl;

	ClapTrap::operator=(other);
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " (" << health << " HP) ";
	if (!health)
		std::cout << "can not high five anyone because it has no hitpoints";
	else
		std::cout << "requests high fives from everyone!";
	std::cout << std::endl;
}
