/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 17:25:54 by sprodatu          #+#    #+#             */
/*   Updated: 2024/08/20 19:02:18 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	/**
	 * check if there is no argument => print * LOUD AND UNBEARABLE FEEDBACK NOISE *
	 * else if there is any, loop through the arguments and print them in uppercase
	 */
	if (argc == 1)
	{
		// endl is prefered over '\n' especially when using variables
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			
        }
		std::cout << std::endl;
	}
	return (0);
}

		// we could also use
		//* if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
		//* 	std::cout << (char)(argv[i][j] - 32);
		//* else
		//* 	std::cout << argv[i][j];
		// in place of the following inner loop
		//	for (int j = 0; argv[i][j]; j++)
		// 		std::cout << (char)toupper(argv[i][j]);
		
		// toupper was preferred for its simplicity 
		// toupper takes an int and returns an int,
		// as we are only dealing with ascii values,
		// we can cast the return value to a char