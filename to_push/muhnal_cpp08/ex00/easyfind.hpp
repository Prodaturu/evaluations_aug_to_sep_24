#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm> // std::find
#include <stdexcept> // std::runtime_error
#include <iostream> // std::cout

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw std::runtime_error("Value not found");

	return it;
}

template <typename T>
void testEasyFind(T& container, int value) {
	try
	{
		typename T::iterator result = easyfind(container, value);
		std::cout << "Found: " << *result << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif
