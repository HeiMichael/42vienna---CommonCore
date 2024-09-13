/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 17:55:17 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 14:45:39 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {} 
HumanB::~HumanB() {}

void HumanB::attack(void) {
    if (_weapon) {
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl; // Access weapon only if not NULL
    }
    else {
        std::cout << _name << " has no weapon to attack with!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon; 
}
