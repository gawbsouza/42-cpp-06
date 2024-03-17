/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:05:32 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 13:38:37 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base::~Base() {}

Base * Base::generate( void )
{
    int num = std::rand() % 3 + 1;
    if (num == 1) return new A();
    if (num == 2) return new B();
    return new C();
}

void Base::identify( Base * p )
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "Class A" << std::endl;
        return;
    }

    if (dynamic_cast<B*>(p)) {
        std::cout << "Class B" << std::endl;
        return;
    }

    if (dynamic_cast<C*>(p)) {
        std::cout << "Class C" << std::endl;
        return;
    } 

    std::cout << "Not identified class" << std::endl;
}

void Base::identity( Base & p )
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "Class A" << std::endl;
        return;
    } catch(std::exception &e) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "Class B" << std::endl;
        return;
    } catch(std::exception &e) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "Class C" << std::endl;
        return;
    } catch(std::exception &e) {}

    std::cout << "Not identified class" << std::endl;
}
