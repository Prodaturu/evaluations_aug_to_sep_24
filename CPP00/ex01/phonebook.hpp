/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 09:10:58 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/21 16:59:33 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include<iostream>
#include<string>
#include "contact.hpp"

// --- ANSI color codes --- //

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"

class PhoneBook
{
	private:
		Contact		_Contact[8];
		int			_index;
		int			_contact_count;
	
	public:
		// --- --- --- Constructor --- --- --- //
		PhoneBook();

		// --- --- --- Destructor --- --- --- //
		~PhoneBook();

		// --- --- --- Setter functions --- --- --- //
		void		add_contact();
		void		search_contact();
		void		display_contact();
		void		display_all_Contact();

		// --- --- --- Getter functions --- --- --- //
		int			get_index() const;
		int			get_max_index() const;
		int			get_contact_count() const;
		Contact		get_contact_at_index(int index) const;
		Contact*	get_contacts() const;

		// --- --- --- Utility functions --- --- --- //
		void		delete_contact(int index);
};

#endif
