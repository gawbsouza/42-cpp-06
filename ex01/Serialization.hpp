/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:17:19 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 12:55:18 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATON_H
# define SERIALIZATION_H

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serialization
{
    
private:

    Serialization( void );
    
public:
    
    static uintptr_t serialize( Data *type );
    static Data * deserialize( uintptr_t raw );
    
};

#endif