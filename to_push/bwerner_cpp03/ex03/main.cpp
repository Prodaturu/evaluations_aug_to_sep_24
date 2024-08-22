/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 04:31:08 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:00:34 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Dippy("Dippy");
	std::cout << std::endl;
	Dippy.whoAmI();
	std::cout << Dippy.getHealth() << " / " << Dippy.getEnergy() << " / " << Dippy.getAttackDamage() << std::endl;
	Dippy.attack("target");
	Dippy.highFivesGuys();
	Dippy.guardGate();
	Dippy.takeDamage(5);
	Dippy.beRepaired(5);
	std::cout << std::endl;
}
