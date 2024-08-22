/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 03:07:13 by mtayebi           #+#    #+#             */
/*   Updated: 2024/07/26 03:16:04 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

# include <iostream>


#define RESET "\033[0m"
#define GREEN  "\033[32m"
#define YELLOW  "\033[33m"
#define RED  "\033[31m"
#define CYAN  "\033[36m"
#define MAGENTA "\033[35m"
#define BOLD_RED     "\033[1m\033[31m"


template <typename Type> void iter(Type *array, int len, void (*f)(Type &))
{
	int	i;
	
	   if (array == nullptr) {
        std::cout << BOLD_RED << "Error: null pointer" << RESET << std::endl;
        exit(EXIT_FAILURE);
    }

	i = 0;
	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

#endif