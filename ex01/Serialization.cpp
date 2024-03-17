/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:39:01 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 12:51:35 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization( void ) {}

uintptr_t Serialization::serialize( Data *type )
{
    return reinterpret_cast<uintptr_t>(type);
}

Data * Serialization::deserialize( uintptr_t raw )
{
    return reinterpret_cast<Data *>(raw);
}
