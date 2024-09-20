/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:14:33 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 12:38:48 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
    protected:
        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;
    
    public:
        FragTrap();                                     //Default Constructor
        FragTrap(std::string name);                     //Constructor
        ~FragTrap();                                    //Destructor
        FragTrap(const FragTrap& others);               //Copy Constructor
        FragTrap& operator=(const FragTrap& others);    //Copy Assignment Operator
        
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        void    print_player_stats(void);
        virtual void    highFivesGuys(void);
};
