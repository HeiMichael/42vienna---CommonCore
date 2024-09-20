/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:14:33 by miheider          #+#    #+#             */
/*   Updated: 2024/09/19 12:33:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
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
        void    highFivesGuys(void);
};
