/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:05:19 by miheider          #+#    #+#             */
/*   Updated: 2024/09/16 13:49:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Default Constructor (Animal) called" << std::endl;
    _type = "Animal";
}

Animal::~Animal() {
    std::cout << "Destructor (Animal) called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Copy Constructor (Animal) called" << std::endl;
    _type = other.getType();
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Copy Assignment Operator (Animal) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << _type << " makes no sound" << std::endl;
}

std::string Animal::getType(void) const {
    return _type;
}
