/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:40:26 by miheider          #+#    #+#             */
/*   Updated: 2024/09/18 11:51:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    
    a = Fixed( 1234.4321f );
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // std::cout << "     ***  test int/float equality  ***     " << std::endl;
    // Fixed e(5);
    // Fixed f(5.0f);
    // std::cout << "e = " << e.toFloat() << std::endl;
    // std::cout << "f = " << f.toFloat() << std::endl;

    // std::cout << "     ***  test assignment  ***     " << std::endl;
    // Fixed g(42.42f);
    // Fixed h;
    // Fixed i;

    // h = g;
    // std::cout << "h after assignment: " << h << std::endl;
    // i = h;
    // std::cout << "i after assignment: " << i << std::endl;

    // std::cout << "     ***  chained assignment  ***     " << std::endl;
    // Fixed j(1);
    // Fixed k;
    // Fixed l;

    // l = k = j;
    // std::cout << "k after assignment: " << k << std::endl;
    // std::cout << "l after assignment: " << l << std::endl;
    
    // std::cout << "     ***  chained assignment  ***     " << std::endl;
    // Fixed m(3.14159f);
    // Fixed n(3.14159f);
    
    // std::cout << "m (3.14159): " << m << std::endl;
    // std::cout << "n (3.14159): " << n << std::endl;
    // std::cout << "m as int: " << m.toInt() << std::endl;
    // std::cout << "n as float: " << n.toFloat() << std::endl;
    
    return 0;
}
