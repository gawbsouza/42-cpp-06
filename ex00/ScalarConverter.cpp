/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:54:00 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/26 22:13:05 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <stdlib.h>
#include <cctype>
#include <limits>

void convertChar( const std::string & value );
void convertInt( const std::string & value );
void convertFloat( const std::string & value );
void convertDouble( const std::string & value );
bool isDisplayable( int value );
bool isNan( const std::string & value );
bool isInf( const std::string & value );
bool isNumeric( const std::string & value );

ScalarConverter::ScalarConverter( void ) {}

void ScalarConverter::convert( const std::string & value )
{
    convertChar(value);
    convertInt(value);
    convertFloat(value);
    convertDouble(value);
}

void convertChar( const std::string & value )
{
    std::cout << "char   : ";

    int intValue = 0;
    const bool numeric = isNumeric(value);
    
    if (isNan(value) || isInf(value) || (!numeric && value.size() > 1)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    
    if (numeric) {
        if (value.find(".") != std::string::npos) {
            intValue = static_cast<int>(atof(value.c_str()));
        } else {
            intValue = atoi(value.c_str());
        }
    }
    
    if (!numeric) {
        if (value.size() > 1) {
            std::cout << "impossible" << std::endl;
            return;
        }
        intValue = static_cast<int>(value.at(0));
    }

    if (intValue <= 0 || intValue > std::numeric_limits<char>::max()) {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (!isDisplayable(intValue)) {
        std::cout << "Non displayable" << std::endl;
        return;
    } 

    std::cout << "'" << static_cast<char>(intValue) << "'" << std::endl;
}

void convertInt( const std::string & value )
{
    std::cout << "Int    : ";
    
    if (!isNumeric(value)) {
        std::cout << "impossible" << std::endl;
        return ;
    }

    // double doubleValue = atof(value.c_str());

    // // Overflow
    //  if (doubleValue > 0 && doubleValue - static_cast<double>(std::numeric_limits<int>::max()) > 0) {
    //     std::cout << "impossible" << std::endl;
    //     return ;
    // }
    // // Underflow
    // if (doubleValue < 0 && (doubleValue * -1) + static_cast<double>(std::numeric_limits<int>::min()) > 0) {
    //     std::cout << "impossible" << std::endl;
    //     return ;
    // }
    
    std::cout << atoi(value.c_str()) << std::endl;
}

void convertFloat( const std::string & value )
{
    std::cout << "Float  : ";
    
    if (isNan(value)) {
        std::cout << "nanf" << std::endl;
        return ;
    }

    if (value.compare("-inff") == 0 || value.compare("-inf") == 0) {
        std::cout << "-inff" << std::endl;
        return ;
    }

    if (value.compare("+inff") == 0 || value.compare("+inf") == 0 || value.compare("inf") == 0) {
        std::cout << "+inff" << std::endl;
        return ;
    }

    if (!isNumeric(value)) {
        std::cout << "impossible" << std::endl;
        return ;
    }

    // double doubleValue = atof(value.c_str());
    
    // // Overflow
    // if (doubleValue > 0 && doubleValue - std::numeric_limits<float>::max() > 0) {
    //     std::cout << "impossible" << std::endl;
    //     return ;
    // }

    // // Underflow
    // if (doubleValue < 0 && (doubleValue * -1) + std::numeric_limits<float>::min() > 0) {
    //     std::cout << "impossible" << std::endl;
    //     return ;
    // }

    float floatValue = static_cast<float>(atof(value.c_str()));
    std::cout.precision(1);
    std::cout << std::fixed << std::showpoint << floatValue << "f" << std::endl;
}

void convertDouble( const std::string & value )
{
    std::cout << "Double : ";
    
    if (isNan(value)) {
        std::cout << "nan" << std::endl;
        return ;
    }

    if (value.compare("-inff") == 0 || value.compare("-inf") == 0) {
        std::cout << "-inf" << std::endl;
        return ;
    }

    if (value.compare("+inff") == 0 || value.compare("+inf") == 0 || value.compare("inf") == 0) {
        std::cout << "+inf" << std::endl;
        return ;
    }

    if (!isNumeric(value)) {
        std::cout << "impossible" << std::endl;
        return ;
    }

    std::cout.precision(1);
    std::cout << std::fixed << std::showpoint << atof(value.c_str()) << std::endl;
}

bool isNumeric( const std::string & value )
{
    bool    signalFound     = false;
    bool    dotFound        = false;
    bool    fFound          = false;
    size_t  numberLength    = 0;
    size_t  size            = value.size();
    size_t  checkPos        = 0;
    
    if (size == 0) return false;
    
    for (size_t i = 0; i < size; i++)
    {
        if (value.at(i) == ' ') {
            checkPos++;
            continue;
        }
        break;
    }
    
    if (checkPos == size) return false;
    
    for (; checkPos < size; checkPos++) 
    {
        char currentChar = value.at(checkPos);
        
        if (currentChar == '+' || currentChar == '-') {
            if (signalFound) {
                return false;
            }
            signalFound = true;
            continue;
        }

        if (currentChar >= '0' && currentChar <= '9') {
            numberLength++;
            continue;
        }
        
        if (currentChar == '.') {
            if (dotFound) {
                return false;
            }
            if (numberLength == 0) {
                return false;
            }
            if (fFound) {
                return false;
            }
            dotFound = true;
            continue;
        }

        if (currentChar == 'f') {
            if (fFound) {
                return false;
            }
            if (numberLength == 0) {
                return false;
            }
            dotFound = true;
        }
    }

    return numberLength > 0;
}

bool isDisplayable( int value ) 
{
    return value > 31 && value < 127;
}

bool isNan( const std::string & value )
{
    if (value.compare("nan") == 0) return true;
    if (value.compare("nanf") == 0) return true;
    return false;
}

bool isInf( const std::string & value )
{
    if (value.compare("-inf") == 0) return true;
    if (value.compare("-inff") == 0) return true;
    if (value.compare("+inf") == 0) return true;
    if (value.compare("+inff") == 0) return true;
    return false;
}