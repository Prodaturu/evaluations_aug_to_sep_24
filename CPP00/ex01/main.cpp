/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:17:23 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/22 17:34:26 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/** Main function logic
 * 1. Create a PhoneBook object
 * 2. Display the main menu containing the following options:
 * 		- ADD
 * 		- SEARCH
 * 		- EXIT
 * 3. Prompt the user to enter an option
 * 		- If the user enters ADD, call the add_contact() function
 * 		- If the user enters SEARCH, call the search_contact() function
 * 4. Repeat steps 2-3 until the user enters EXIT
 * 		- If the user enters EXIT, exit the program
 */

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	input = "";
	while (input != "EXIT")
	{
		std::cout << "Enter ADD, SEARCH or EXIT: ";
		std::cin >> input;

		// Convert input to uppercase for case-insensitive comparison
		// this is done using the std::transform function
		// std::transform takes 4 arguments:
		
		std::transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			std::cout << "Exiting program..." << std::endl;
		else if (input == "DELETE")
			phonebook.delete_contact();
		else
			std::cout << "Invalid input. Please enter ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
