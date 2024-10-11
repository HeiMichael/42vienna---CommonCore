/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:42:38 by miheider          #+#    #+#             */
/*   Updated: 2024/09/25 17:39:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Default Constructor (Cat) called" << std::endl;
    _type = "Cat";
    _brain = new(std::nothrow) Brain;
    if (!_brain) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
}

Cat::~Cat() {
    std::cout << "Destructor (Cat) called" << std::endl;
    delete _brain;
}

Cat::Cat(const Cat& other) {
    std::cout << "Copy Constructor (Cat) called" << std::endl;
    _type = other.getType();
    _brain = new(std::nothrow) Brain;
    if (!_brain) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
    *_brain = *other._brain;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Copy Assignment Operator (Cat) called" << std::endl;
    if (this != &other) {
        _type = other.getType();
        *_brain = *other._brain;
    }
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << _type << " makes meow" << std::endl;
}

std::string Cat::getType(void) const {
    return _type;
}

std::string Cat::get_ideas(int index) const {
    return _brain->get_ideas(index);
}

void        Cat::set_ideas(std::string message, int i) {
    _brain->set_ideas(message, i);
}

