/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:58:23 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 13:42:55 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{

    std::cout << "Pointer Classes" << std::endl;
    A a; Base::identify(&a);
    B b; Base::identify(&b);
    C c; Base::identify(&c);

    std::cout << "Reference Classes" << std::endl;
    Base *base;

    base = &a; Base::identify(base);
    base = &b; Base::identify(base);
    base = &c; Base::identify(base);

    std::cout << "Random Classes" << std::endl;
    Base *random;

    for (int i = 0; i < 5; i++) {
        random = Base::generate();
        Base::identify(random);
        delete random;
    }

    return 0;
}