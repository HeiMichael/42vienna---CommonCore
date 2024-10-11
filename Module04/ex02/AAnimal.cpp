/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:05:19 by miheider          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:52 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "Default Constructor (AAnimal) called" << std::endl;
    _type = "Animal";
}

AAnimal::~AAnimal() {
    std::cout << "Destructor (AAnimal) called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) {
    std::cout << "Copy Constructor (AAnimal) called" << std::endl;
    _type = other.getType();
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "Copy Assignment Operator (AAnimal) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void AAnimal::makeSound(void) const {
    std::cout << _type << " makes no sound" << std::endl;
}

std::string AAnimal::getType(void) const {
    return _type;
}
