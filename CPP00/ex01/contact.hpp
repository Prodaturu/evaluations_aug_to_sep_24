/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:39:23 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/21 12:20:01 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef Contact_HPP
# define Contact_HPP

#include <iostream>
#include <string>

class Contact
{
	// Its good practice  to use _ starting for variable names in private
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		int			_index;
	
	public:
		// --- --- --- Constructor --- --- --- //
		Contact();

		// --- --- --- Destructor --- --- --- //
		~Contact()
		{
			std::cout << "Contact object destroyed" << std::endl;
		};
		// --- --- --- Setter functions --- --- --- //
		void		set_first_name(const std::string &first_name);
		void		set_last_name(const std::string last_name);
		void		set_nickname(const std::string nickname);
		void		set_phone_number(const std::string phone_number);
		void		set_darkest_secret(const std::string darkest_secret);
		void		set_index(int index);

		// --- --- --- Getter functions --- --- --- //
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;
		int			get_index() const;
};

#endif

/** const at end of funciton declaration
 * 
 * When we use the const keyword at the end of a function declaration,
 * tells compiler that this function will not modify the object.
 * Hence, it is a read-only function.
 * In the above example:
 * We have declared the getter functions as const because
 * these functions will not modify the object and only
 * read the values, and return them.
 */

// first name, last name, nickname, phone number, and
// darkest secret. A saved contact can’t have empty fields.
