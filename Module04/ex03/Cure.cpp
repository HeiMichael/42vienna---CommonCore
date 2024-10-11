/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:43 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 07:29:47 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    // std::cout << "Default Constructor (Cure) called" << std::endl;
}

Cure::~Cure() {
    // std::cout << "Destructor (Cure) called" << std::endl;
}

Cure::Cure (const Cure& other) {
    _type = other.getType();
    // std::cout << "Copy constructor (Cure) called" << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    // std::cout << "Copy assignment operator (Cure) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

AMateria* Cure::clone() const {
    AMateria *copy = new(std::nothrow) Cure(*this);
    if (!copy) {
        std::cout << "Memory allocation failed" << std::endl;
        return NULL;
    }
    return copy;
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

std::string Cure::getType( void ) const {
    return _type;
}

