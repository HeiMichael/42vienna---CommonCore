/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:29:40 by miheider          #+#    #+#             */
/*   Updated: 2024/09/23 14:40:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Default Constructor (WrongAnimal) called" << std::endl;
    _type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Destructor (WrongAnimal) called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
    std::cout << "Copy Constructor (WrongAnimal) called" << std::endl;
    _type = other.getType();
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Copy Assignment Operator (WrongAnimal) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void WrongAnimal::makeSound(void) const {
    std::cout << _type << " makes no sound" << std::endl;
}

std::string WrongAnimal::getType(void) const {
    return _type;
}
