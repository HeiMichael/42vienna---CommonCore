/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:15:23 by miheider          #+#    #+#             */
/*   Updated: 2024/09/18 14:20:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//Default Constructor
Point::Point(): _x(Fixed(0)), _y(Fixed(0)) {
    // std::cout << "Default constructor (Point) called." << std::endl;
}

//Destructor
Point::~Point() {
    // std::cout << "Destructor (Point) called." << std::endl;
}

//Float-Float Constructor
Point::Point(float const x, float const y): _x(Fixed(x)), _y(Fixed(y)) {
    // std::cout << "Float-Float Constructor (Point) called." << std::endl;
}

//Copy Constructor
Point::Point(const Point& other): _x(other.get_x()), _y(other.get_y()) {
    // std::cout << "Copy Constructor (Point) called." << std::endl;
}

//Copy Assignment Operator
Point& Point::operator=(const Point& other) {
    // std::cout << "Copy assignment operator (Point) called" << std::endl;
    if (this != &other) {
        (Fixed(_x)) = other.get_x();
        (Fixed(_y)) = other.get_y();
    }
    return *this;
}

Fixed   Point::get_x(void) const {
    return this->_x;
}

Fixed   Point::get_y(void) const {
    return this->_y;
}
