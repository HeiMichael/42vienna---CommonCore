/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:50:25 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:13:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) {
    _type = weapon;
}

Weapon::~Weapon() {
    
}

std::string  Weapon::getType() const {
    return _type;
}

void    Weapon::setType(std::string another_weapon) {
    _type = another_weapon;
}
