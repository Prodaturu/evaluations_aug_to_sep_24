/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:08:32 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:36:42 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
					ScavTrap(void);
					ScavTrap(const std::string& name);
					ScavTrap(const ScavTrap& other);
				~	ScavTrap(void);

		ScavTrap&	operator=(const ScavTrap& other);

		void		attack(const std::string& target);
		void		guardGate(void);

	protected:
		void		initValues(void);
		bool		guarding;
};

#endif
