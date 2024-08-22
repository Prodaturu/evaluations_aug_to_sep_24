/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:31:32 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/22 19:10:15 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class	ClapTrap
{
	public:
					ClapTrap(void);
					ClapTrap(const std::string& name);
					ClapTrap(const ClapTrap& other);
				~	ClapTrap(void);

		ClapTrap&	operator=(const ClapTrap& other);

		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		void		setAttackDamage(unsigned int amount);

	private:
		std::string		name;
		unsigned int	health;
		unsigned int	energy;
		unsigned int	attack_damage;
};

#endif
