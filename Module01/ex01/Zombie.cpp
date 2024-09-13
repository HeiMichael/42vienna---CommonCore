/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:04:16 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 13:22:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() {
    std::cout << "Default constructor called." << std::endl;
}

Zombie::~Zombie() {
    std::cout << _name << " destroyed." << std::endl;
}

void Zombie::announce() {
    std::cout << _name << " created." << std::endl;
}

void Zombie::set_name(std::string zombie_name) {
    _name = zombie_name;
}
