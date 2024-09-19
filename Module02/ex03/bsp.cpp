/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:31:43 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 13:20:56 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include<cmath>

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

static Fixed triangle_area(Point const a, Point const b, Point const c) {
    Fixed area;
    
    area = ((a.get_x() * (b.get_y() - c.get_y())
    + (b.get_x() * (c.get_y() - a.get_y()))
    + (c.get_x() * (a.get_y() - b.get_y()))) / Fixed(2));
    
    if (area < 0)
        area = area * Fixed(-1);
    
    return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const p) {
    Fixed area_total = triangle_area(a, b, c);
    Fixed area_1 = triangle_area(a, b, p);
    Fixed area_2 = triangle_area(a, c, p);
    Fixed area_3 = triangle_area(b, c, p);

    if (area_1 == 0 || area_2 == 0 || area_3 == 0)
        return false;
    
    return ((area_1 + area_2 + area_3) == area_total);
}    
