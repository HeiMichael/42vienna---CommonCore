/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:49:43 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 09:57:58 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::_fractional_bits = 8;

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed) {
	// std::cout << "<< overload (Fixed) called" << std::endl;
	ostream << fixed.toFloat();
	return (ostream);
}

//Default Constructor
Fixed::Fixed() {
    _fixed_point_number = 0;
    std::cout << "Default constructor (Fixed) called" << std::endl;
}

//Int Constructor
Fixed::Fixed(const int parameter) {
    std::cout << "Int constructor (Fixed) called   " << parameter << _fixed_point_number << std::endl;
    _fixed_point_number = parameter << _fractional_bits;
}

//Float Constructor
Fixed::Fixed(const float parameter) {
    std::cout << "Float constructor (Fixed) called" << std::endl;
    _fixed_point_number = roundf(parameter * (1 << _fractional_bits));
}

//Destructor
Fixed::~Fixed() {
    std::cout << "Destructor (Fixed) called" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed& others) {
    std::cout << "Copy constructor (Fixed) called" << std::endl;
    *this = others;
}

//Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& others) {
    std::cout << "Copy assignment operator (Fixed) called" << std::endl;
    if (this != &others)
        _fixed_point_number = others.getRawBits();
    return *this;
}

int     Fixed::getRawBits( void ) const {
    return _fixed_point_number;
}

void    Fixed::setRawBits( int const raw ) {
    _fixed_point_number = raw;
}

float   Fixed::toFloat( void ) const {
    return ((float)_fixed_point_number / (float)(1 << _fractional_bits));
}

int     Fixed::toInt( void ) const {
    return _fixed_point_number >> _fractional_bits;
}

