/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:58:23 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/26 22:20:20 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main( int argc, char *argv[] ) {

    if (argc != 2) {
        std::cout << "usage ./convert <value>" << std::endl;
        return 1;
    }

    std::string value = argv[1];

    ScalarConverter::convert(value);
    
    return 0;
}