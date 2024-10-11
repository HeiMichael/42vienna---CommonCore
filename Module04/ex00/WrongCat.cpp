/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:59 by miheider          #+#    #+#             */
/*   Updated: 2024/09/23 14:34:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    std::cout << "Default Constructor (WrongCat) called" << std::endl;
    _type = "WrongCat";
}

WrongCat::~WrongCat() {
    std::cout << "Destructor (WrongCat) called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) {
    std::cout << "Copy Constructor (WrongCat) called" << std::endl;
    _type = other.getType();
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "Copy Assignment Operator (WrongCat) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << _type << " makes meow" << std::endl;
}

std::string WrongCat::getType(void) const {
    return _type;
}
