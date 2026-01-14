/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:36:47 by gcosta-m          #+#    #+#             */
/*   Updated: 2026/01/14 10:36:48 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    else
    {
        try
        {
            RPN calculator;
            int result = calculator.rpnCalculate(argv[1]);
            std::cout << result << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
            return 1;
        }
    }
        return 0;
}