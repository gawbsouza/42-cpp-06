/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasouza <gasouza@student.42sp.org.br >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 12:57:51 by gasouza           #+#    #+#             */
/*   Updated: 2024/03/17 13:04:48 by gasouza          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

class Base
{
    
public:

    virtual         ~Base( void );

    static Base *   generate( void );
    static void     identify( Base * p );
    static void     identity( Base & p );
    
};

#endif