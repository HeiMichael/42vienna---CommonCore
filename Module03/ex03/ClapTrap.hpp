/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:43:50 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 08:19:03 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class ClapTrap {
    //private:
    protected:
        std::string     _name;
        unsigned int    _hit_points;
        unsigned int    _energy_points;
        unsigned int    _attack_damage;
    
    public:
        ClapTrap();                                     //Default Constructor
        ClapTrap(std::string name);                     //Constructor
        virtual ~ClapTrap();                                    //Destructor
        ClapTrap(const ClapTrap& others);               //Copy Constructor
        ClapTrap& operator=(const ClapTrap& others);    //Copy Assignment Operator
        
        virtual void attack(const std::string& target);
        virtual void takeDamage(unsigned int amount);
        virtual void beRepaired(unsigned int amount);
        void print_player_stats(void);
};
