/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:32 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 07:20:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

//Default constructor
AMateria::AMateria() {
    // std::cout << "Default constructor (AMateria) called" << std::endl;
}

//Destructor
AMateria::~AMateria() {
    // std::cout << "Destructor (AMateria) called" << std::endl;
}

//Copy constructor
AMateria::AMateria(const AMateria& other) {
    _type = other.getType();
    // std::cout << "Copy constructor (AMateria) called" << std::endl;
}

//Copy assignment operator
AMateria& AMateria::operator=(const AMateria& other) {
    // std::cout << "Copy assignment operator (AMateria) called" << std::endl;
    if (this != &other)
        _type = other.getType();
    return *this;
}

//Constructor
AMateria::AMateria(std::string const& type) : _type(type) {
    // std::cout << "Constructor (AMateria) called" << std::endl;
}

//Memberfunctions
std::string const & AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target) {
    (void) target;
    //virtual function, will be overridden by derived classes (ice, cure)
}

//clone function is pure virtual function
