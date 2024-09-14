/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:13:51 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 08:31:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//Default Constructor
FragTrap::FragTrap() {
    std::cout << "Default constructor (FragTrap) called" << std::endl;
}

//Constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    _name = name;
    _hit_points = 100;
    _energy_points = 100;
    _attack_damage = 30;
    std::cout << "Constructor (FragTrap std::string) created " << _name << std::endl;
}

//Destructor
FragTrap::~FragTrap() {
    std::cout << "Destructor (FragTrap) called" << std::endl;
}

//Copy Constructor
FragTrap::FragTrap(const FragTrap& others) {
    std::cout << "Copy Constructor (FragTrap) called" << std::endl;
    this->_name = others._name;
    this->_hit_points = others._hit_points;
    this->_energy_points = others._energy_points;
    this->_attack_damage = others._attack_damage;
}

//Copy Assignment Operator
FragTrap& FragTrap::operator=(const FragTrap& others) {
    std::cout << "Copy Assignment Operator (FragTrap) called" << std::endl;
    if (this != &others) {
        this->_name = others._name;
        this->_hit_points = others._hit_points;
        this->_energy_points = others._energy_points;
        this->_attack_damage = others._attack_damage;
    }
    return *this;
}
        
void    FragTrap::attack(const std::string& target) {
    if (_hit_points <= 0)
        std::cout << "FragTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "FragTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
                << _attack_damage << " points of damage!" << std::endl;
        _energy_points -= 1;
    }
}

void    FragTrap::takeDamage(unsigned int amount) {
    std::cout << "FragTrap " << _name << " takes " << amount << " points damage." << std::endl;
    if (_hit_points >= amount) {
        _hit_points -= amount;
        if (_hit_points == 0)
            std::cout << "Player " << _name << " died." << std::endl;
    } else {
        _hit_points = 0;
        std::cout << "Player " << _name << " died." << std::endl;
    }
}

void    FragTrap::beRepaired(unsigned int amount) {
    if (_hit_points <= 0)
        std::cout << "FragTrap " << _name << " cannot attack. No hit points left." << std::endl;
    else if (_energy_points <= 0)
        std::cout << "FragTrap " << _name << " cannot attack. No energy points left." << std::endl;
    else {
        std::cout << "FragTrap " << _name << " gets " << amount << " hit points back." << std::endl;
        _energy_points -= 1;
        _hit_points += amount;
    }
}

void    FragTrap::print_player_stats(void) {
    std::cout << "\n_name: " << _name << "\n_hit_points: " << _hit_points << "\n_energy_points: " << _energy_points << "\n_attack_damage: " << _attack_damage << std::endl;
    std::cout << std::endl;
}

void    FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " highfives the guys." << std::endl;
}
