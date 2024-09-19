/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:28:16 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 18:56:08 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
    private:
        Fixed const _x;
        Fixed const _y;
        //anything useful
    public:
        Point();                                        //Default Constructor
        ~Point();                                       //Destructor
        Point(float const x, float const y);            //Float-Float Constructor
        Point(const Point& other);                      //Copy Constructor
        Point& operator=(const Point& other);    //Copy Assignment Constructor
        
        //anything useful
        
        Fixed   get_x(void) const;
        Fixed   get_y(void) const;
        
};
