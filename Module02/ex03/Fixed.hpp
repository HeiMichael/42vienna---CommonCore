/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:09:37 by miheider          #+#    #+#             */
/*   Updated: 2024/09/11 09:24:51 by miheider         ###   ########.fr       */
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
        Fixed(const Fixed& test);                 //Copy Constructor
        Fixed& operator=(const Fixed test);      //Copy Assignment Operator
        //comparison operators
        bool	operator>(const Fixed test) const;
        bool	operator<(const Fixed test) const;
        bool	operator>=(const Fixed test) const;
        bool 	operator<=(const Fixed test) const;
        bool 	operator==(const Fixed test) const;
        bool 	operator!=(const Fixed test) const;
        //arithmetic operators
        Fixed	operator+(const Fixed& test) const;
        Fixed	operator-(const Fixed& test) const;
        Fixed	operator*(const Fixed& test) const;
        Fixed	operator/(const Fixed& test) const;
        //increment/decrement
        Fixed&  operator++();
        Fixed&  operator--();
        Fixed   operator++(int);
        Fixed   operator--(int);
        //member functions
        static Fixed& min(Fixed &one, Fixed &two);
        static const Fixed& min(const Fixed &one, const Fixed &two);
        static Fixed& max(Fixed &one, Fixed &two);
        static const Fixed& max(const Fixed &one, const Fixed &two);
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
        float	toFloat( void ) const;
        int		toInt( void ) const;
};
