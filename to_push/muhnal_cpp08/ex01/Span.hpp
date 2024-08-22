#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);
	template <typename Iterator>
	void addNumbers(Iterator begin, Iterator end);
	int shortestSpan() const;
	int longestSpan() const;

private:
	std::vector<int> numbers_;
	unsigned int max_size_;
};

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end)
{
	while (begin != end)
	{
		if (numbers_.size() >= max_size_)
		{
			throw std::runtime_error("Span is already full");
		}
		numbers_.push_back(*begin);
		++begin;
	}
}

#endif // SPAN_HPP
