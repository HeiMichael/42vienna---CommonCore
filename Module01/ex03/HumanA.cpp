/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:32:28 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:13:21 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon_type(weapon) { // Use initializer list
}

HumanA::~HumanA() {}

void HumanA::attack(void) {
    std::cout << _name << ": attacks with their " << _weapon_type.getType() << std::endl; // Ensure _weapon_type is valid
}
