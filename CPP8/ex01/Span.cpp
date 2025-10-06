#include "Span.hpp"

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize) {
        throw std::out_of_range("Cannot add more numbers, span is full");
    }
    numbers.push_back(num);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int minNum = *std::min_element(numbers.begin(), numbers.end());
    int maxNum = *std::max_element(numbers.begin(), numbers.end());
    return maxNum - minNum;
}

