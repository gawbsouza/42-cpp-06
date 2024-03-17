/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:24:44 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 12:49:03 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include <string>

class Data
{
    
private:
    
    std::string _value;
    
public:

    Data( void );
    Data( const std::string & value );
    Data( const Data & ref );
    ~Data();

    Data & operator=( const Data & ref );

    std::string getValue( void );
};

#endif