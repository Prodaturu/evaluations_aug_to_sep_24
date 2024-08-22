/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_functions.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:15:41 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/18 15:22:41 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;

	public:
		void	set_first_name(std::string first_name)
		{
			_first_name =  first_name;
		}

		void	set_last_name(std::string last_name)
		{
			_last_name = last_name;
		}

		void	display_contact();
};

void	Contact::display_contact()
{
	std::cout << "Full name: " << _first_name;
	std::cout << _last_name << std::endl;
}

int	main(void)
{
	Contact Jacky;
	Contact default_contact;

	Jacky.set_first_name("Jacky");
	Jacky.set_last_name("Chan");

	Jacky.display_contact();

	default_contact.set_first_name("My N");
	default_contact.set_last_name("igga");
	default_contact.display_contact();
}
