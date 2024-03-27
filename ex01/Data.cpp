/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:28:44 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/26 22:32:10 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data( void ): _value("") {}
Data::Data( const std::string & value ): _value(value) {}
Data::Data( const Data & ref ) { *this = ref; }
Data::~Data() {}

Data & Data::operator=( const Data & ref )
{
    if (this != &ref ) {
        this->_value = ref._value;
    }
    return *this;
}

std::string Data::getValue( void ) const
{
    return this->_value;
}
