/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:43:47 by miheider          #+#    #+#             */
/*   Updated: 2024/09/20 12:59:38 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"

int main() {
    ClapTrap player("Evaluator");

    // player.print_player_stats();
    player.attack("Bocal");
    // player.print_player_stats();
    player.beRepaired(2);
    // player.print_player_stats();
    player.takeDamage(3);
    // player.print_player_stats();
    player.attack("you");
    // player.print_player_stats();
    player.attack("another enemy");
    // player.print_player_stats();
    player.takeDamage(12);
    // player.print_player_stats();
    
    return 0;
}
