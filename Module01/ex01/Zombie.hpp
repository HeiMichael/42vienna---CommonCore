/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:04:19 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:14:13 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include<iostream>

class Zombie {

    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();   
        void announce(void);
        void set_name(std::string zombie_name);
};

#endif
