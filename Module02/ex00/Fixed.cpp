/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:53 by miheider          #+#    #+#             */
/*   Updated: 2024/09/18 13:46:05 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::_fractional_bits = 8;

//Default Constructor
Fixed::Fixed() {
    _fixed_point_number = 0;
    std::cout << "Default constructor (Fixed) called" << std::endl;
}

//Destructor
Fixed::~Fixed(){
    std::cout << "Destructor (Fixed) called" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor (Fixed) called" << std::endl;
    _fixed_point_number = other.getRawBits();
}

//Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator (Fixed) called" << std::endl;
    if (this != &other)
        _fixed_point_number = other.getRawBits();
    return *this;
}

//returns the raw value of the fixed-point value
int     Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixed_point_number;
}

//sets the raw value of the fixed-point number
void    Fixed::setRawBits( int const raw ) {
    this->_fixed_point_number = raw;
}
