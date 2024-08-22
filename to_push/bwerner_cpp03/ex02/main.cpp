/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 04:31:08 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/23 15:22:19 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	Clappy("Clappy");
	std::cout << std::endl;

	FragTrap	Fraggy("Fraggy");
	std::cout << std::endl;

	Fraggy.highFivesGuys();
	std::cout << std::endl;

	Clappy.setAttackDamage(3);
	Clappy.attack("Fraggy");
	Fraggy.takeDamage(3);
	std::cout << std::endl;

	Fraggy.attack("Clappy");
	Clappy.takeDamage(20);
	std::cout << std::endl;

	Fraggy.beRepaired(3);
	std::cout << std::endl;
}
