/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:29:02 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 12:42:53 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Default Constructor
DiamondTrap::DiamondTrap() 
    : ClapTrap("default_clap_name"), ScavTrap("default"), FragTrap("default"), _name("default") {
    std::cout << "Default Constructor (DiamondTrap) called" << std::endl;
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
}

// Constructor (std::string)
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
    _hit_points = FragTrap::_hit_points;
    _energy_points = ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
    std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

// Destructor
DiamondTrap::~DiamondTrap() {
    std::cout << "Destructor (DiamondTrap) called" << std::endl;
}

// Copy Constructor
DiamondTrap::DiamondTrap(const DiamondTrap& others)
    : ClapTrap(others.ClapTrap::_name), ScavTrap(others.ScavTrap::_name), FragTrap(others.FragTrap::_name), _name(others._name) {
    std::cout << "Copy Constructor (DiamondTrap) called." << std::endl;
    this->_hit_points = others._hit_points;
    this->_energy_points = others._energy_points;
    this->_attack_damage = others._attack_damage;
}

// Copy Assignment Operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& others) {
    std::cout << "Copy Assignment Operator (DiamondTrap) called." << std::endl;
    if (this != &others) {
        ClapTrap::operator=(others);
        ScavTrap::operator=(others);
        FragTrap::operator=(others);
        this->_name = others._name;
        this->_hit_points = others._hit_points;
        this->_energy_points = others._energy_points;
        this->_attack_damage = others._attack_damage;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount) {
    std::cout << "DiamondTrap " << _name << " takes " << amount << " points of damage." << std::endl;
    if (_hit_points >= amount) {
        _hit_points -= amount;
        if (_hit_points == 0) {
            std::cout << "DiamondTrap " << _name << " died." << std::endl;
        }
    } else {
        _hit_points = 0;
        std::cout << "DiamondTrap " << _name << " died." << std::endl;
    }
}

void DiamondTrap::beRepaired(unsigned int amount) {
    if (_hit_points <= 0) {
        std::cout << "DiamondTrap " << _name << " cannot be repaired. No hit points left." << std::endl;
    } else if (_energy_points <= 0) {
        std::cout << "DiamondTrap " << _name << " cannot be repaired. No energy points left." << std::endl;
    } else {
        std::cout << "DiamondTrap " << _name << " gets " << amount << " hit points back." << std::endl;
        _energy_points -= 1;
        _hit_points += amount;
    }
}

void DiamondTrap::print_player_stats() const {
    std::cout << "\n_name: " << _name 
            << "\n_hit_points: " << _hit_points 
            << "\n_energy_points: " << _energy_points 
            << "\n_attack_damage: " << _attack_damage 
            << std::endl;
}

void DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << _name  << ". ClapTrap name: " 
            << ClapTrap::_name << std::endl;
}

void DiamondTrap::highFivesGuys(void) {
    std::cout << "DiamondTrap " << _name << " highfives the guys." << std::endl;
}

void DiamondTrap::guardGate() {
    std::cout << "DiamondTrap is now in Gate keeper mode" << std::endl;
}
