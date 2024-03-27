/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:58:23 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/26 22:30:46 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialization.hpp"
#include <iostream>


int main()
{
    Data sampleData = Data("Sample Data");

    std::cout << " --- Data before serialization ---" << std::endl;
    std::cout << "Value: " << sampleData.getValue() << std::endl;

    uintptr_t serializedData = Serialization::serialize(&sampleData);

    Data *deserializatedData = Serialization::deserialize(serializedData);

    std::cout << std::endl;

    std::cout << " --- Data after deserialization ---" << std::endl;
    std::cout << "Value: " << deserializatedData->getValue() << std::endl;

    std::cout << std::endl;

    if (&sampleData == deserializatedData) {
        std::cout << "### POINTERS ARE EQUALS ###" << std::endl;
    } else {
        std::cout << "### !! POINTERS ARE DIFERENT !! ###" << std::endl;
    }

    std::cout << std::endl;

    return 0;
}