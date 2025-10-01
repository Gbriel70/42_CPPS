/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcosta-m <gcosta-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:42 by gcosta-m          #+#    #+#             */
/*   Updated: 2025/10/01 14:48:43 by gcosta-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_HPP
#define CLASS_HPP

#include "Base.hpp"

class ClassA : public Base {
public:
    void display() const {
        std::cout << "ClassA instance" << std::endl;
    }
};

class ClassB : public Base {
public:
    void display() const {
        std::cout << "ClassB instance" << std::endl;
    }
};

class ClassC : public Base {
public:
    void display() const {
        std::cout << "ClassC instance" << std::endl;
    }
};

#endif