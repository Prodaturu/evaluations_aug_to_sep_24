/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:48:32 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/22 22:59:28 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

/**
 * @brief Main function
 * 
 * @param argc Number of arguments
 * @param argv Arguments
 * 
 * @return int 0 if success, 1 if error
 * 
 * @throw Error if wrong number of arguments
 * @throw Error if evaluation failed
 * 
 * @see RPN (class)
 * @see RPN::evaluate (method) the expression
 * 
 * @note The main function evaluates the expression given as argument
 * and prints the result
 * @note If the number of arguments is not 2, an error is thrown
 * @note then the expression is evaluated and the result is printed
 * @note If the evaluation fails, an error is thrown and the program returns 1
 * @note If the evaluation is successful, the result is printed and the program returns 0
 */
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: wrong number of arguments" << std::endl;
		return (1);
	}

	try
	{
		int result;
		RPN rpn;

		result = rpn.evaluate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
