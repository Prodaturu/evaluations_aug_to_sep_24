/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 04:31:08 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/22 22:12:52 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	Clappy("Clappy");
	std::cout << std::endl;

	ScavTrap	Scavvy("Scavvy");
	std::cout << std::endl;

	Scavvy.guardGate();
	std::cout << std::endl;

	Clappy.setAttackDamage(3);
	Clappy.attack("Scavvy");
	Scavvy.takeDamage(3);
	std::cout << std::endl;

	Scavvy.attack("Clappy");
	Clappy.takeDamage(20);
	std::cout << std::endl;

	Scavvy.beRepaired(3);
	std::cout << std::endl;
}
