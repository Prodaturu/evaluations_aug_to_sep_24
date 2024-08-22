/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:27:53 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:34:54 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
						DiamondTrap(void);
						DiamondTrap(const std::string& name);
						DiamondTrap(const DiamondTrap& other);
					~	DiamondTrap(void);

		DiamondTrap&	operator=(const DiamondTrap& other);

		void			whoAmI(void);

	private:
		void			initValues(void);
		std::string		name;
};

#endif
