#include "Span.hpp"
#include <algorithm> // for std::sort, std::min_element, std::max_element
#include <climits>   // for INT_MAX

Span::Span(unsigned int n) : max_size_(n) {}

Span::Span(const Span& other) : numbers_(other.numbers_), max_size_(other.max_size_) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		numbers_ = other.numbers_;
		max_size_ = other.max_size_;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (numbers_.size() >= max_size_)
	{
		throw std::runtime_error("Span is already full");
	}
	numbers_.push_back(number);
}

int Span::shortestSpan() const
{
	if (numbers_.size() < 2)
	{
		throw std::runtime_error("Not enough numbers to find a span");
	}
	std::vector<int> sorted_numbers = numbers_;
	std::sort(sorted_numbers.begin(), sorted_numbers.end());
	int min_span = INT_MAX;
	for (size_t i = 1; i < sorted_numbers.size(); ++i)
	{
		int span = sorted_numbers[i] - sorted_numbers[i - 1];
		if (span < min_span)
		{
			min_span = span;
		}
	}
	return min_span;
}

int Span::longestSpan() const
{
	if (numbers_.size() < 2)
	{
		throw std::runtime_error("Not enough numbers to find a span");
	}
	int min_value = *std::min_element(numbers_.begin(), numbers_.end());
	int max_value = *std::max_element(numbers_.begin(), numbers_.end());
	return max_value - min_value;
}
