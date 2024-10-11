/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:57:11 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 11:07:13 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default Constructor (Brain) called" << std::endl;
    _ideas = new(std::nothrow) std::string[100];
    if (!_ideas) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "an idea is created";
    }
}

Brain::~Brain() {
    std::cout << "Destructor (Brain) called" << std::endl;
    delete [] _ideas;
}

Brain::Brain(const Brain& other) {
    std::cout << "Copy Constructor (Brain) called" << std::endl;
    _ideas = new(std::nothrow) std::string[100];
    if (!_ideas) {
        std::cout << "Memory allocation failed." << std::endl;
        return ;
    }
    for (int i = 0; i < 100; i++) {
        *this->_ideas = other.get_ideas(i);
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Copy Assignment Operator (Brain) called" << std::endl;
    if (this != &other) {
        delete [] _ideas;
        _ideas = new(std::nothrow) std::string[100];
        if (!_ideas) {
            std::cout << "Memory allocation failed." << std::endl;
            return *this;
        }
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other.get_ideas(i);
        }
    }
    return *this;
}

std::string Brain::get_ideas(int index) const {
    return this->_ideas[index];
}

void        Brain::set_ideas(std::string message, int i) {
    _ideas[i] = message;
}

