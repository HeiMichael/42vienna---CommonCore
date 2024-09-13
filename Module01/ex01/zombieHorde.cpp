/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:04:21 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 08:22:37 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *horde = new Zombie[N];
    
    if (N <= 0 || N > 2147483647 || name == "") {
        std::cout << "Error: invalid input." << std::endl;
        return NULL;
    }
    
    for (int i = 0; i < N; i++) {
        horde[i].set_name(name);
        horde[i].announce();
    }
    return horde;
    
}
