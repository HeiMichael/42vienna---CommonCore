/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:41:42 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 10:08:09 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void) {
    Zombie  *heapZombie;

    heapZombie = newZombie("Michi");
    heapZombie->announce();

    randomChump("evaluator");
    //stackZombie.announce();           //error: stackZombie not visible in this scope 

    delete heapZombie;
    
    return 0;
}
