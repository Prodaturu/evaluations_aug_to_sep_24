#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int &x) {
    std::cout << x << " ";
}

void incrementInt(int &x) {
    x++;
}

void printDouble(double &x) {
    std::cout << x << " ";
}

void squareDouble(double &x) {
    x *= x;
}

void printString(std::string &x) {
    std::cout << x << " ";
}

void appendExclamation(std::string &x) {
    x += "!";
}

int main() {

    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLen, printInt);
    std::cout << std::endl;

    iter(intArray, intArrayLen, incrementInt);
    std::cout << "Incremented int array: ";
    iter(intArray, intArrayLen, printInt);
    std::cout << std::endl;

    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleArrayLen = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original double array: ";
    iter(doubleArray, doubleArrayLen, printDouble);
    std::cout << std::endl;

    iter(doubleArray, doubleArrayLen, squareDouble);
    std::cout << "Squared double array: ";
    iter(doubleArray, doubleArrayLen, printDouble);
    std::cout << std::endl;

    std::string stringArray[] = {"Hello", "World", "This", "Is", "Test"};
    size_t stringArrayLen = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original string array: ";
    iter(stringArray, stringArrayLen, printString);
    std::cout << std::endl;

    iter(stringArray, stringArrayLen, appendExclamation);
    std::cout << "Modified string array: ";
    iter(stringArray, stringArrayLen, printString);
    std::cout << std::endl;

    return 0;
}