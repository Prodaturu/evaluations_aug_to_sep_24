#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

class Span {
public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    template <typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    int shortestSpan() const;
    int longestSpan() const;

private:
    std::vector<int> numbers;
    unsigned int max_size;

    class SpanFullException : public std::exception {
    public:
        const char* what() const throw();
    };

    class NotEnoughElementsException : public std::exception {
    public:
        const char* what() const throw();
    };
};
#endif