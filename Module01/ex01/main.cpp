/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:04:13 by miheider          #+#    #+#             */
/*   Updated: 2024/08/24 11:34:31 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void) {
    int N = 7;
    Zombie *many_zombies;

    many_zombies = zombieHorde(N, "evaluator");
    delete[] many_zombies;

    return 0;
}
