/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:52 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:53 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "function.hpp"
#include "Class.hpp"

void testIdentifyFunctions() {
    std::cout << "\n=== TESTING IDENTIFY FUNCTIONS ===" << std::endl;
    
    ClassA* a = new ClassA();
    ClassB* b = new ClassB();
    ClassC* c = new ClassC();
    
    std::cout << "\n--- Testing ClassA ---" << std::endl;
    identify(a);
    identify(*a);
    
    std::cout << "\n--- Testing ClassB ---" << std::endl;
    identify(b);
    identify(*b);
    
    std::cout << "\n--- Testing ClassC ---" << std::endl;
    identify(c);
    identify(*c);
    
    std::cout << "\n--- Testing NULL pointer ---" << std::endl;
    Base* nullPtr = NULL;
    identify(nullPtr);
    
    delete a;
    delete b;
    delete c;
}

int main()
{
    std::cout << "=== GENERATE AND IDENTIFY TEST ===" << std::endl;

    Base* obj1 = generate();
    std::cout << "Generated object address: " << obj1 << std::endl;
    identify(obj1);
    identify(*obj1);

    std::cout << "==================================" << std::endl;

    Base* obj2 = generate();
    std::cout << "Generated object address: " << obj2 << std::endl;
    identify(obj2);
    identify(*obj2);

    std::cout << "==================================" << std::endl;

    Base* obj3 = generate();
    std::cout << "Generated object address: " << obj3 << std::endl;
    identify(obj3);
    identify(*obj3);


    std::cout << "==================================" << std::endl;

    testIdentifyFunctions();

    delete obj1;
    delete obj2;
    delete obj3;
    return 0;
}