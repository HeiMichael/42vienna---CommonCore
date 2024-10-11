/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:08:01 by miheider          #+#    #+#             */
/*   Updated: 2024/10/04 14:54:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Default Constructor (Dog) called" << std::endl;
    _type = "Dog";
    _brain = new(std::nothrow) Brain;
    if (!_brain) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Destructor (Dog) called" << std::endl;
}

Dog::Dog(const Dog& other) {
    std::cout << "Copy Constructor (Dog) called" << std::endl;
    _type = other.getType();
    _brain = new(std::nothrow) Brain;
    if (!_brain) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
    *_brain = *other._brain;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Copy Assignment Operator (Cat) called" << std::endl;
    if (this != &other) {
        _type = other.getType();
        *_brain = *other._brain;
    }
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << _type << " makes woof!" << std::endl;
}

std::string Dog::getType(void) const {
    return _type;
}

std::string Dog::get_ideas(int index) const {
    return _brain->get_ideas(index);
}

void        Dog::set_ideas(std::string message, int i) {
    _brain->set_ideas(message, i);
}


