/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:38 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 08:55:23 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() {

}

Character::Character(std::string name) {
    _name = name;
    std::cout << "Character " << _name << " created." << std::endl;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::~Character() {
    std::cout << "Character " << _name << " destroyed." << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

Character::Character(const Character& other) {
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL) {
            _inventory[i] = other._inventory[i]->clone();  // Deep copy
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        for (int i = 0; i < 4; i++) {
            if (_inventory[i] != NULL) {
                delete _inventory[i];
            }
            if (other._inventory[i] != NULL) {
                _inventory[i] = other._inventory[i]->clone();
            } else {
                _inventory[i] = NULL;
            }
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return _name;
}

void Character::equip(AMateria* m) {
    if (!m)
        return ;

    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m;
            return;
        }
    }
    std::cout << "Inventory is full, cannot equip more Materia." << std::endl;
    delete m;
}

void Character::unequip(int index) {
    if (index < 0 || index > 3) {
        std::cout << "slot " << index << " is not available" << std::endl;
    }
    if (index >= 0 && index < 4) {
        if (_inventory[index] != NULL) {
            delete _inventory[index];
            _inventory[index] = NULL;
        }
        else {
            std::cout << "slot " << index << " is not equipped" << std::endl;
        }
    }
}   

void Character::use(int index, ICharacter& target) {
    if ((index >= 0 && index < 4) && _inventory[index] != NULL)
        _inventory[index]->use(target);
    else {
        std::cout << "Cannnot use Materia." << std::endl;
    }
}
