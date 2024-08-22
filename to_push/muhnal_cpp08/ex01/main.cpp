#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl; // Expected: 2
	std::cout << sp.longestSpan() << std::endl; // Expected: 14

	// Test with addNumbers
	Span sp2 = Span(10000);
	std::vector<int> numbers;
	for (int i = 0; i < 10000; ++i)
	{
		numbers.push_back(i);
	}
	sp2.addNumbers(numbers.begin(), numbers.end());

	std::cout << sp2.shortestSpan() << std::endl; // Expected: 1
	std::cout << sp2.longestSpan() << std::endl;  // Expected: 9999

	return 0;
}
