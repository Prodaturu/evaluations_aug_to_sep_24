/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 04:31:08 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/22 19:22:19 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Clappy("Clappy");
	ClapTrap	Trappy("Trappy");

	Clappy.setAttackDamage(4);
	std::cout << "\n";

	Clappy.attack("Trappy");
	Trappy.takeDamage(4);
	std::cout << "\n";

	Clappy.attack("Trappy");
	Trappy.takeDamage(4);
	std::cout << "\n";
	
	Trappy.beRepaired(3);
	std::cout << "\n";

	Clappy.attack("Trappy");
	Trappy.takeDamage(4);
	std::cout << "\n";

	Clappy.attack("Trappy");
	Trappy.takeDamage(4);
	std::cout << "\n";

	Trappy.attack("Clappy");
	Trappy.beRepaired(3);
	std::cout << "\n";

	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.attack("random target");
	Clappy.beRepaired(3);
	std::cout << "\n";
}
