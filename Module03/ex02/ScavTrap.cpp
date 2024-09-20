/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:12:54 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 08:09:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//Default Constructor
ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "Default constructor (ScavTrap) called" << std::endl;
}

//Constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hit_points = 100;
    _energy_points = 50;
    _attack_damage = 20;
    std::cout << "Constructor (ScavTrap std::string) created " << _name << std::endl;
}

//Destructor
ScavTrap::~ScavTrap() {
    std::cout << "Destructor (ScavTrap) called" << std::endl;
}

//Copy Constructor
ScavTrap::ScavTrap(const ScavTrap& others) : ClapTrap(others) {
    std::cout << "Copy Constructor (ScavTrap) called" << std::endl;
    this->_name = others._name;
    this->_hit_points = others._hit_points;
    this->_energy_points = others._energy_points;
    this->_attack_damage = others._attack_damage;
}

//Copy Assignment Operator
ScavTrap& ScavTrap::operator=(const ScavTrap& others) {
    std::cout << "Copy Assignment Operator (ScavTrap) called" << std::endl;
    if (this != &others) {
        this->_name = others._name;
        this->_hit_points = others._hit_points;
        this->_energy_points = others._energy_points;
        this->_attack_damage = others._attack_damage;
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_hit_points <= 0)
        std::cout << "ScavTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "ScavTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << std::endl;
        _energy_points -= 1;
    }
}

void ScavTrap::takeDamage(unsigned int amount) {
    std::cout << "ScavTrap " << _name << " takes " << amount << " points damage." << std::endl;
    if (_hit_points >= amount) {
        _hit_points -= amount;
        if (_hit_points == 0)
            std::cout << "Player " << _name << " died." << std::endl;
    } else {
        _hit_points = 0;
        std::cout << "Player " << _name << " died." << std::endl;
    }
}

void ScavTrap::beRepaired(unsigned int amount) {
    if (_hit_points <= 0)
        std::cout << "ScavTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "ScavTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "ScavTrap " << _name << " gets " << amount << " hit points back." << std::endl;
        _energy_points -= 1;
        _hit_points += amount;
    }
}

void    ScavTrap::print_player_stats(void) {
    std::cout << "\n_name: " << _name << "\n_hit_points: " << _hit_points << "\n_energy_points: " << _energy_points << "\n_attack_damage: " << _attack_damage << std::endl;
    std::cout << std::endl;
}
