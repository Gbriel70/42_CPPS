/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 13:52:21 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/12/12 14:00:35 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
	std::vector<int> vec2;
    std::list<int> lst;

    for (int i = 0; i < 5; i++)
	{
        vec.push_back(i * 10);
        lst.push_back(i + 1);
    }
	vec2.push_back(1);
	vec2.push_back(1);
	vec2.push_back(2);
    try{
        std::vector<int>::iterator v_it = easyfind(vec, 40);
        std::cout << "Found in vector " << *v_it << std::endl;

        std::list<int>::iterator l_it = easyfind(lst, 3);
        std::cout << "Found in list " << *l_it << std::endl;
		
		std::vector<int>::iterator v2_it = easyfind(vec2, 2);
        std::cout << "Found in vector " << *v2_it << std::endl;
        
        easyfind(vec, 99);

    } catch (std::exception &e){
        std::cerr << "Error " << e.what() << std::endl;    
    }

    return (0);
}