/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:02:58 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/04/29 11:02:59 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int main(void)
{
	string s = "HI THIS IS BRAIN";
	string *stringPTR = &s;
	string &stringREF = s;

	cout << "The memory address of the string variable: " << &s << endl;
	cout << "The memory address held by stringPTR: " << stringPTR << endl;
	cout << "The memory address held by stringREF: " << &stringREF << endl;

	cout << "\n------------------------" << endl;

	cout << "The value of the string variable: " << s << endl;
	cout << "The value pointed to by stringPTR: " << *stringPTR << endl;
	cout << "The value pointed to by stringREF: " << stringREF << endl;

}