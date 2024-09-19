/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:27:14 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 09:51:03 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
bool bsp( Point const a, Point const b, Point const c, Point const point);

int main() {
    //Triangle
    Point tri_a(0, 0);
    Point tri_b(6, 3);
    Point tri_c(-3, 5);
    
    //Points to test
    Point to_check1(2, -1);             //not in triangle
    Point to_check2(5.5f, 4.2f);        //not in triangle
    Point to_check3(-1, 2);             //in triangle
    Point to_check4(0.9f, 2.1f);        //in triangle
    Point to_check5(2, 1);              //on the edge
    Point to_check6(-1.5f, 2.5);        //on the edge
            

        
    if (bsp(tri_a, tri_b, tri_c, to_check1) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;
    
    if (bsp(tri_a, tri_b, tri_c, to_check2) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;
    
    if (bsp(tri_a, tri_b, tri_c, to_check3) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;
    
    if (bsp(tri_a, tri_b, tri_c, to_check4) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;
    
    if (bsp(tri_a, tri_b, tri_c, to_check5) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;
    
    if (bsp(tri_a, tri_b, tri_c, to_check6) == true)
        std::cout << "Point is within the triangle" << std::endl;
    else
        std::cout << "Point is not within the triangle" << std::endl;

    return 0;
}
