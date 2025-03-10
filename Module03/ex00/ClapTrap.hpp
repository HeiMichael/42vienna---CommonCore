/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:43:50 by miheider          #+#    #+#             */
/*   Updated: 2024/09/12 10:00:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class ClapTrap {
    private:
        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;
    
    public:
        ClapTrap();                                     //Default Constructor
        ClapTrap(std::string name);                     //Constructor
        ~ClapTrap();                                    //Destructor
        ClapTrap(const ClapTrap& others);               //Copy Constructor
        ClapTrap& operator=(const ClapTrap& others);    //Copy Assignment Operator
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void print_player_stats(void);
};
