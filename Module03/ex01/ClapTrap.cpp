/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:43:54 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 13:04:19 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "Default Constructor (ClapTrap) called." << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0) {
    std::cout << "Constructor (ClapTrap std::string) called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor (ClapTrap) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& others) {                 //Copy Constructor
    std::cout << "Copy Constructor (ClapTrap) called." << std::endl;
    this->_name = others._name;
    this->_hit_points = others._hit_points;
    this->_energy_points = others._energy_points;
    this->_attack_damage = others._attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& others) {      //Copy Assignment Operator
    std::cout << "Copy Assignment Operator (ClapTrap) called." << std::endl;
    if (this != &others) {
        this->_name = others._name;
        this->_hit_points = others._hit_points;
        this->_energy_points = others._energy_points;
        this->_attack_damage = others._attack_damage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << std::endl;
        _energy_points -= 1;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " takes " << amount << " points damage." << std::endl;
    if (_hit_points >= amount) {
        _hit_points -= amount;
        if (_hit_points == 0)
            std::cout << "Player " << _name << " died." << std::endl;
    } else {
        _hit_points = 0;
        std::cout << "Player " << _name << " died." << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "ClapTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "ClapTrap " << _name << " gets " << amount << " hit points back." << std::endl;
        _energy_points -= 1;
        _hit_points += amount;
    }
}

void    ClapTrap::print_player_stats(void) {
    std::cout << "\n_name: " << _name << "\n_hit_points: " << _hit_points << "\n_energy_points: " << _energy_points << "\n_attack_damage: " << _attack_damage << std::endl;
    std::cout << std::endl;
}
