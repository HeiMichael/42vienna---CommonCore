/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:51:48 by miheider          #+#    #+#             */
/*   Updated: 2024/09/18 11:52:01 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    // std::cout << "     ***  testing setRawBits() function  ***     " << std::endl;
    // Fixed d;
    // d.setRawBits(12345);
    // std::cout << "d getRawBits = " << d.getRawBits() << std::endl;

    // std::cout << "     ***  multiple assignments  ***     " << std::endl;
    // Fixed e;
    // Fixed f;
    // Fixed g;

    // e.setRawBits(42);
    // f = e;
    // g = f;
    // std::cout << "e getRawBits = " << e.getRawBits() << std::endl;
    // std::cout << "f getRawBits = " << f.getRawBits() << std::endl;
    // std::cout << "g getRawBits = " << g.getRawBits() << std::endl;

    // std::cout << "     ***  test copy constructor  ***     " << std::endl;
    // Fixed h;
    // h.setRawBits(13579);
    // Fixed i(h);
    // std::cout << "h getRawBits = " << h.getRawBits() << std::endl;
    // std::cout << "i getRawBits = " << i.getRawBits() << std::endl;
    
    // std::cout << "     ***  negative values  ***     " << std::endl;
    // Fixed j;
    // j.setRawBits(-123);
    // std::cout << "j getRawBits = " << j.getRawBits() << std::endl;

    // std::cout << "     ***  multiple instances  ***     " << std::endl;
    // Fixed k, l, m;
    // k.setRawBits(42);
    // l.setRawBits(142);
    // m.setRawBits(242);
    // std::cout << "k getRawBits = " << k.getRawBits() << std::endl;
    // std::cout << "l getRawBits = " << l.getRawBits() << std::endl;
    // std::cout << "m getRawBits = " << m.getRawBits() << std::endl;

    return 0;
}
