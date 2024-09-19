/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:32:12 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 13:22:48 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::_fractional_bits = 8;

float   Fixed::toFloat( void ) const {
    return ((float)_fixed_point_number / (float)(1 << _fractional_bits));
}

int     Fixed::toInt( void ) const {
    return _fixed_point_number >> _fractional_bits;
}

int     Fixed::getRawBits( void ) const {
    return this->_fixed_point_number;
}

void    Fixed::setRawBits( int const raw ) {
    _fixed_point_number = raw;
}

std::ostream	&operator<<(std::ostream &ostream, Fixed const &fixed) {
	// std::cout << "<< overload (Fixed) called" << std::endl;
	ostream << fixed.toFloat();
	return (ostream);
}

//Default Constructor
Fixed::Fixed() {
	_fixed_point_number = 0;
    // std::cout << "Default constructor (Fixed) called" << std::endl;
}

//Int Constructor
Fixed::Fixed(const int parameter) {
    _fixed_point_number = parameter << _fractional_bits;
    // std::cout << "Int constructor (Fixed) called   " << parameter << _fixed_point_number << std::endl;
}

//Float Constructor
Fixed::Fixed(const float parameter) {
    // std::cout << "Float constructor (Fixed) called" << std::endl;
    _fixed_point_number = roundf(parameter * (1 << _fractional_bits));
}

//Destructor
Fixed::~Fixed() {
    // std::cout << "Destructor called (Fixed)" << std::endl;
}

//Copy Constructor
Fixed::Fixed(const Fixed& test) {
    // std::cout << "Copy constructor (Fixed) called" << std::endl;
    this->_fixed_point_number = test._fixed_point_number;
}

//Copy Assignment Operator
Fixed& Fixed::operator=(const Fixed test) {
    // std::cout << "Copy assignment operator (Fixed) called" << std::endl;
    if (this != &test)
        _fixed_point_number = test.getRawBits();
    return *this;
}

//comparison operators
bool	Fixed::operator>(const Fixed test) const {
	// std::cout << "Comparison operator '>' (Fixed) called" << std::endl;
	if (this->_fixed_point_number > test.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed test) const {
	// std::cout << "Comparison operator '<' (Fixed) called" << std::endl;
	if (this->_fixed_point_number < test.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed test) const {
	// std::cout << "Comparison operator '>=' (Fixed) called" << std::endl;
	if (this->_fixed_point_number >= test.getRawBits())
		return true;
	else
		return false;
}

bool 	Fixed::operator<=(const Fixed test) const {
	// std::cout << "Comparison operator '<=' (Fixed) called" << std::endl;
	if (this->_fixed_point_number <= test.getRawBits())
		return true;
	else
		return false;
}

bool 	Fixed::operator==(const Fixed test) const {
	// std::cout << "Comparison operator '==' (Fixed) aclled" << std::endl;
	if (_fixed_point_number == test.getRawBits())
		return true;
	else
		return false;
}

bool 	Fixed::operator!=(const Fixed test) const {
	// std::cout << "Comparison operator '!=' (Fixed) called" << std::endl;
	if (this->_fixed_point_number != test.getRawBits())
		return true;
	else
		return false;
}

//arithmetic operators
Fixed	Fixed::operator+(const Fixed& test) const {
	// std::cout << "arithmetic operator '+' (Fixed) called" << std::endl;
    return Fixed(this->toFloat() + test.toFloat());
}

Fixed	Fixed::operator-(const Fixed& test) const {
	// std::cout << "arithmetic operator '-' (Fixed) called" << std::endl;
    return Fixed(this->toFloat() - test.toFloat());
}

Fixed	Fixed::operator*(const Fixed& test) const {
	// std::cout << "arithmetic operator '*' (Fixed) called" << std::endl;
    return Fixed(this->toFloat() * test.toFloat());
}

Fixed	Fixed::operator/(const Fixed& test) const {
	// std::cout << "arithmetic operator '/' (Fixed) called" << std::endl;
    return Fixed(this->toFloat() / test.toFloat());
}

//increment/decrement
Fixed& Fixed::operator++() {
	// std::cout << "pre-increment operator (Fixed) called" << std::endl;
	_fixed_point_number += 1;
	return *this;
}

Fixed& Fixed::operator--() {
	// std::cout << "pre-decrement operator (Fixed) called" << std::endl;
	_fixed_point_number -= 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	// std::cout << "post-increment operator (Fixed) called" << std::endl;
	Fixed save = *this;

	this->_fixed_point_number += 1;
	return save;
}

Fixed   Fixed::operator--(int) {
	// std::cout << "post-decrement operator (Fixed) called" << std::endl;
	Fixed save = *this;

	this->_fixed_point_number -= 1;
	return save;
}

//min_max
Fixed& Fixed::min(Fixed &one, Fixed &two) {
	// std::cout << "min function (Fixed) called" << std::endl;
	if (one.toFloat() < two.toFloat())
		return one;
	else
		return two;
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two) {
	// std::cout << "min const function (Fixed) called" << std::endl;
	if (one.toFloat() < two.toFloat())
		return one;
	else
		return two;
}

Fixed& Fixed::max(Fixed &one, Fixed &two) {
	// std::cout << "max function (Fixed) called" << std::endl;
	if (one.toFloat() > two.toFloat())
		return one;
	else
		return two;	
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two) {
	// std::cout << "max const function (Fixed) called" << std::endl;
	if (one.toFloat() > two.toFloat())
		return one;
	else
		return two;
}
