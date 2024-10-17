/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:09:03 by miheider          #+#    #+#             */
/*   Updated: 2024/10/08 09:46:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>
#include <string>

int main( void ) {
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#01          basic test form subject              |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        int a = 2;
        int b = 3;

        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::cout << std::endl;
    }
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#02          testing diff data types              |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        int a = 2;
        int b = 3;

        std::cout << "a = " << a << ", b = " << b << std::endl;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::cout << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        std::cout << "c = " << c << ", d = " << d << std::endl;
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
        std::cout << std::endl;

        float   e = 3.7f;
        float   f = 15.98f;

        ::swap(e, f);
        std::cout << "e = " << e << ", f = " << f << std::endl;
        ::swap(e, f);
        std::cout << "e = " << e << ", f = " << f << std::endl;
        std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
        std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
        std::cout << std::endl;

        double  g = 3.74545;
        double  h = 15.9848754;

        std::cout << "g = " << g << ", h = " << h << std::endl;
        ::swap(g, h);
        std::cout << "g = " << g << ", h = " << h << std::endl;
        std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
        std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;
    }
    
    return 0;
}
