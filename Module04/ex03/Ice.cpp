/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:50 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 07:29:39 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    // std::cout << "Default Constructor (Ice) called" << std::endl;
}

Ice::~Ice() {
    // std::cout << "Destructor (Ice) called" << std::endl;
}

Ice::Ice (const Ice& other) {
    _type = other.getType();
    // std::cout << "Copy constructor (Ice) called" << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    // std::cout << "Copy assignment operator (Ice) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

AMateria* Ice::clone() const {
    AMateria *copy = new(std::nothrow) Ice(*this);
    if (!copy) {
        std::cout << "Memory allocation failed" << std::endl;
        return NULL;
    }
    return copy;
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

std::string Ice::getType( void ) const {
    return _type;
}
