/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:41:17 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 07:55:16 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
    private:
        int                 _fixed_point_number;
        static const int    _fractional_bits;

    public:
        Fixed();                                    //Default Constructor
        Fixed(const int parameter);                 //Constructor (int)
        Fixed(const float parameter);               //Constructor (float)
        ~Fixed();                                   //Destructor
        Fixed(const Fixed& others);                 //Copy Constructor
        Fixed& operator=(const Fixed& others);      //Copy Assignment Operator
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
};
