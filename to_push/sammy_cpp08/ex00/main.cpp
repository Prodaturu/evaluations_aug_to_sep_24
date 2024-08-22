#include <iostream>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
	int i = 0;
	while (i < 6)
	{
		vec.push_back(i);
		i ++;
	}
    try {
        std::vector<int>::iterator it_vec = easyfind(vec, 3);
        std::cout << "Found in vector: " << *it_vec << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it_vec_fail = easyfind(vec, 10);
        std::cout << "Found in vector: " << *it_vec_fail << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}