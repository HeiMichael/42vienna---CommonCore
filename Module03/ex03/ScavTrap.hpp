/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:08:25 by miheider          #+#    #+#             */
/*   Updated: 2024/09/12 10:37:53miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
    protected:
        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;
    
    public:
        ScavTrap();                                     //Default Constructor
        ScavTrap(std::string name);                     //Constructor
        ~ScavTrap();                                    //Destructor
        ScavTrap(const ScavTrap& others);               //Copy Constructor
        ScavTrap& operator=(const ScavTrap& others);    //Copy Assignment Operator
        
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    print_player_stats(void);
        virtual void    guardGate();
};
