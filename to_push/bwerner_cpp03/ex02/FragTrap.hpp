/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwerner <bwerner@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:00:27 by bwerner           #+#    #+#             */
/*   Updated: 2024/07/25 21:42:23 by bwerner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
					FragTrap(void);
					FragTrap(const std::string& name);
					FragTrap(const FragTrap& other);
				~	FragTrap(void);

		FragTrap&	operator=(const FragTrap& other);

		void		highFivesGuys(void);
};

#endif
