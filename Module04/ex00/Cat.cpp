/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:42:38 by miheider          #+#    #+#             */
/*   Updated: 2024/09/16 13:49:42 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default Constructor (Cat) called" << std::endl;
    _type = "Cat";
}

Cat::~Cat() {
    std::cout << "Destructor (Cat) called" << std::endl;
}

Cat::Cat(const Cat& other) {
    std::cout << "Copy Constructor (Cat) called" << std::endl;
    _type = other.getType();
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Copy Assignment Operator (Cat) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << _type << " makes meow" << std::endl;
}

std::string Cat::getType(void) const {
    return _type;
}
