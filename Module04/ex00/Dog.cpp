/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:08:01 by miheider          #+#    #+#             */
/*   Updated: 2024/09/23 14:45:28 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default Constructor (Dog) called" << std::endl;
    _type = "Dog";
}

Dog::~Dog() {
    std::cout << "Destructor (Dog) called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Copy Constructor (Dog) called" << std::endl;
    _type = other.getType();
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Copy Assignment Operator (Dog) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << _type << " makes woof!" << std::endl;
}

std::string Dog::getType(void) const {
    return _type;
}
