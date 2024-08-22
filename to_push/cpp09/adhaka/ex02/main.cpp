/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adhaka <adhaka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:54:34 by adhaka            #+#    #+#             */
/*   Updated: 2024/07/08 14:17:35 by adhaka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isPositiveInteger(const std::string &str)
{
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: No input provided." << std::endl;
		return 1;
	}

	std::vector<int> inputNumbers;

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (!isPositiveInteger(arg))
		{
			std::cerr << "Error: Invalid input. Only positive integers are allowed." << std::endl;
			return 1;
		}

		int number = std::atoi(arg.c_str());
		inputNumbers.push_back(number);
	}

	try
	{
		PmergeMe sorter;
		sorter.sortAndMeasure(inputNumbers);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
