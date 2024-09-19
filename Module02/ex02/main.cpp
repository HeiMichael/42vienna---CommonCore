/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:08:32 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 13:24:05 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    // std::cout << "(a >= b): " << (a >= b) << std::endl;
    // std::cout << "(a > b): " << (a > b) << std::endl;
    // std::cout << "(a <= b): " << (a <= b) << std::endl;
    // std::cout << "(a < b): " << (a < b) << std::endl;
    // std::cout << "(a == b): " << (a == b) << std::endl;
    // std::cout << "(a != b): " << (a != b) << std::endl;
    // std::cout << "(a + b): " << (a + b) << std::endl;
    // std::cout << "(a - b): " << (a - b) << std::endl;
    // std::cout << "(a * b): " << (a * b) << std::endl;
    // std::cout << "(b * a): " << (b * a) << std::endl;
    // std::cout << "(a / b): " << (a / b) << std::endl;
    // std::cout << "(b / a): " << (b / a) << std::endl;
    // std::cout << "a++: " << a++ << std::endl;
    // std::cout << "a--: " << a-- << std::endl;
    // std::cout << "++a: " << ++a << std::endl;
    // std::cout << "--a: " << --a << std::endl;

    return 0;
}
