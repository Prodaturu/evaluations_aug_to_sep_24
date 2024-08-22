/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:33:14 by mtayebi           #+#    #+#             */
/*   Updated: 2024/07/26 03:15:38 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"iter.hpp"
#include "iter.hpp"

void printElement(int &element) {
    std::cout << GREEN << element << RESET << " ";
}

void incrementElement(int &element) {
    element += 1;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int len = sizeof(array) / sizeof(array[0]);

    std::cout << CYAN << "Array elements before increment: " << RESET;
    iter(array, len, printElement);
    std::cout << std::endl;

    iter(array, len, incrementElement);

    std::cout << MAGENTA << "Array elements after increment: " << RESET;
    iter(array, len, printElement);
    std::cout << std::endl;

    return 0;
}
