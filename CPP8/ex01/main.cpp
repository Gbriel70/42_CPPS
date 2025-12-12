/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:52:39 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/12/12 13:52:40 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    try {
        sp.addNumber(42);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    Span largeSpan = Span(10000);
    std::vector<int> largeVector;
    for (int i = 0; i < 10000; ++i) {
        largeVector.push_back(i * 2);
    }
    largeSpan.addNumbers(largeVector.begin(), largeVector.end());
    std::cout << "Shortest Span in largeSpan: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span in largeSpan: " << largeSpan.longestSpan() << std::endl;

    return 0;
}