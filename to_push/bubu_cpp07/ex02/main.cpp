/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtayebi <mtayebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 20:33:14 by mtayebi           #+#    #+#             */
/*   Updated: 2024/07/26 05:06:34 by mtayebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#include "Array.hpp"
#include <iostream>
#include <exception>

int main() {
    try {
        // Test default constructor
        Array<int> defaultArray;
        std::cout << "Default array size: " << defaultArray.size() << std::endl;

        // Test constructor with specific size
        Array<int> sizedArray(5);
        std::cout << "Sized array size: " << sizedArray.size() << std::endl;
        for (unsigned int i = 0; i < sizedArray.size(); ++i) {
            std::cout << "sizedArray[" << i << "]: " << sizedArray[i] << std::endl;
        }

        // Test copy constructor
        Array<int> copiedArray(sizedArray);
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << "copiedArray[" << i << "]: " << copiedArray[i] << std::endl;
        }

        // Test assignment operator
        Array<int> assignedArray = sizedArray;
        std::cout << "Assigned array size: " << assignedArray.size() << std::endl;
        for (unsigned int i = 0; i < assignedArray.size(); ++i) {
            std::cout << "assignedArray[" << i << "]: " << assignedArray[i] << std::endl;
        }

        // Test modifying original array and checking copy
        sizedArray[0] = 42;
        std::cout << "sizedArray[0] after modification: " << sizedArray[0] << std::endl;
        std::cout << "copiedArray[0] after sizedArray modification: " << copiedArray[0] << std::endl;
        std::cout << "assignedArray[0] after sizedArray modification: " << assignedArray[0] << std::endl;

        // Test out of bounds access
        std::cout << "Trying to access out of bounds element:" << std::endl;
        try {
            std::cout << defaultArray[0] << std::endl; // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        try {
            std::cout << sizedArray[10] << std::endl; // Should throw an exception
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
