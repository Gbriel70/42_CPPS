#ifndef SPAN_HPP
#define SPAN_HPP    

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span 
{
    private:
        unsigned int maxSize;
        std::vector<int> numbers;

    public:
        Span(unsigned int n) : maxSize(n) {}
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        template<typename InputIt>
        void addNumbers(InputIt begin, InputIt end) {
            if (numbers.size() + std::distance(begin, end) > maxSize) {
                throw std::out_of_range("Cannot add more numbers, span will exceed its maximum size");
            }
            numbers.insert(numbers.end(), begin, end);
        }
};

#endif