#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main() {
	// 1. empty container
	std::vector<int> emptyVec;
	testEasyFind(emptyVec, 1); // expected: "Value not found"

	// 2. Finding a value in a container first last and middle
	// 2. Konteynerin başında, ortasında ve sonunda bulunan bir değeri arama
	std::vector<int> vec;
	vec.push_back(100);
	vec.push_back(200);
	vec.push_back(300);
	vec.push_back(400);
	vec.push_back(500);
	testEasyFind(vec, 100); //1st arg: container, 2nd arg: value to find
	testEasyFind(vec, 300);
	testEasyFind(vec, 500);

	// 3. Finding a value that does not exist in the container
	testEasyFind(vec, 6); // expected: "Value not found"

	// 4. Single element container test
	std::list<int> singleElemList;
	singleElemList.push_back(42);
	testEasyFind(singleElemList, 42); // print the found value
	testEasyFind(singleElemList, 24); // expected: "Value not found"

	// 5. Large container test (10000 elements)
	std::deque<int> largeDeque(10000, 0);
	largeDeque[9999] = 42;
	testEasyFind(largeDeque, 42); // print the found value
	testEasyFind(largeDeque, 100); // expected: "Value not found"
	return 0;
}
