#include "Span.hpp"


Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span &other) : numbers(other.numbers), max_size(other.max_size) {}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        numbers = other.numbers;
        max_size = other.max_size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= max_size) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());

    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < min_span) {
            min_span = span;
        }
    }
    return min_span;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NotEnoughElementsException();
    }

    int min_value = *std::min_element(numbers.begin(), numbers.end());
    int max_value = *std::max_element(numbers.begin(), numbers.end());
    return max_value - min_value;
}

const char* Span::SpanFullException::what() const throw() {
    return "Span is full. Cannot add more numbers.";
}

const char* Span::NotEnoughElementsException::what() const throw() {
    return "Not enough elements in Span to find a span.";
}
