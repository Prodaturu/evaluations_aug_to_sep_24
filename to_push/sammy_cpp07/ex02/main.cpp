#include <iostream>
#include "Array.hpp"
#include <string>

int main() {

try {
    Array<int> arr(20);
    arr[4] = 42;
    std::cout << arr[4] << std::endl;
        Array<int> arr2(arr);
    std::cout << arr2[4] << std::endl;
        Array<int> arr3 = arr;
    std::cout << arr3[0] << std::endl;
    std::cout << arr3[4] << std::endl;

    Array<std::string> arr4(3);
	arr4[0] = "Sami";
    std::cout << arr4[0] << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);}