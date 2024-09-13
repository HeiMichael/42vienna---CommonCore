/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:42:00 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:14:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

#include<iostream>

class Zombie {

    private:
        std::string		_name;
    
    public:
		void	announce(void);
		Zombie(std::string zombie_name);
		~Zombie();
    
};

#endif
