/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:27:13 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/21 17:01:05 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

// --- --- --- Constructor --- --- --- //

PhoneBook::PhoneBook() : _index(0), _contact_count(0)
{
	std::cout << "Phonebook object created" << std::endl;
}

// --- --- --- Destructor --- --- --- //

PhoneBook::~PhoneBook()
{
	std::cout << "Phonebook object destroyed" << std::endl;
}

// --- --- --- Getter functions --- --- --- //

int		PhoneBook::get_index() const
{
	return (_index);
}

void	PhoneBook::add_contact()
{
	int			del_index;

	std::string	first_name, last_name, nickname, phone_number, darkest_secret;
	
	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter nickname: ";
	std::cin >> nickname;
	std::cout << "Enter phone number: ";
	std::cin >> phone_number;
	std::cout << "Enter darkest secret: ";
	std::cin >> darkest_secret;
	if (_index < 8)
	{
		_Contact[_index].set_first_name(first_name);
		_Contact[_index].set_last_name(last_name);
		_Contact[_index].set_nickname(nickname);
		_Contact[_index].set_phone_number(phone_number);
		_Contact[_index].set_darkest_secret(darkest_secret);
		_index++;
		_contact_count++;
	}
	else
	{
		delete_contact(del_index);
		_index = del_index;
		_Contact[_index].set_first_name(first_name);
		_Contact[_index].set_last_name(last_name);
		_Contact[_index].set_nickname(nickname);
		_Contact[_index].set_phone_number(phone_number);
		_Contact[_index].set_darkest_secret(darkest_secret);
	}
}