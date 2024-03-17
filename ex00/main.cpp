/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:58:23 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 09:38:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

// int main( int argc, char *argv[] ) {

//     if (argc != 2) {
//         std::cout << "usage ./convert <value>" << std::endl;
//         return 1;
//     }

//     std::string value(argv[1]);
int main() {

    std::string values[] = {
        "0", "-50", "10", "32", //Non displayble
        "a", "*", "T", " ", "&", "=", //Chars
        "345", "aa", "-588", "128", "-128", //impossibles
        "58.0", "42.4545f", "88", "-45.f", "+42.0004", //numbers
        "21474836483", //big number
        "nan", "nanf", // nan
        "-inf", "-inff", "+inf", "+inff", "inf",

        "fim"
    };

    for (int i = 0;; i++) {
        if (values[i].compare("fim") == 0) break;
        
        std::cout << "Testando: " << values[i] << std::endl;
        ScalarConverter::convert(values[i]);
    }
    

    return 0;
}