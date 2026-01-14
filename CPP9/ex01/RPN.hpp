/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:36:54 by gcosta-m          #+#    #+#             */
/*   Updated: 2026/01/14 10:36:55 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <algorithm>
# include <sstream>
# include <iostream>
# include <fstream>
# include <string>
# include <stdexcept>

# define DEBUG 0

class RPN
{
    private:
        std::stack<int> m_num_stack;

        bool isOperator(std::string const& token);
        bool isNum(std::string const& token);
        int strToInt(std::string const& str);
        void executeOperation(std::string const& op);
    public:
        RPN();
        RPN(RPN const& other);
        RPN &operator=(RPN const& other);
        ~RPN();

        int rpnCalculate(std::string const& expression);
};

#endif