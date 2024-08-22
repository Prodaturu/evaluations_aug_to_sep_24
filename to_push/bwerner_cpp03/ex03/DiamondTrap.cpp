/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:27:56 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:36:05 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// static unsigned int	getScavTrapEnergy(void)
// {
// 	ScavTrap	tmp;
// 	return (tmp.getEnergy());
// }

void	DiamondTrap::initValues(void)
{
	unsigned int tmp = energy;
	FragTrap::initValues();
	energy = tmp;
}

DiamondTrap::DiamondTrap(void) : name(ClapTrap::name)
{
	std::cout << "DiamondTrap " << this->name << " constructed with default constructor" << std::endl;

	ClapTrap::name += "_clap_name";
	initValues();
}

DiamondTrap::DiamondTrap(const std::string& name) :	ClapTrap(name + "_clap_name"), name(name)
{
	std::cout << "DiamondTrap " << this->name << " constructed with name constructor" << std::endl;

	initValues();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other), name(other.name)
{
	std::cout << "DiamondTrap " << this->name << " constructed with copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Destructor called on DiamondTrap " << name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "Assignment operator called on DiamondTrap " << name << std::endl;

	ScavTrap::operator=(other);
	name = other.name;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << name << "\nClapTrap name:    " << ClapTrap::name << std::endl;
}
