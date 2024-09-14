/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:43:47 by miheider          #+#    #+#             */
/*   Updated: 2024/09/12 11:43:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    FragTrap student("Jakob");
    
    student.print_player_stats();
    student.attack("Bocal");
    student.print_player_stats();
    student.beRepaired(2);
    student.print_player_stats();
    student.takeDamage(3);
    student.print_player_stats();
    student.attack("you");
    student.print_player_stats();
    student.attack("another enemy");
    student.print_player_stats();
    student.highFivesGuys();
    student.takeDamage(120);
    student.print_player_stats();
    
    // ScavTrap player("Evaluator");
    // player.print_player_stats();
    // player.attack("Bocal");
    // player.print_player_stats();
    // player.beRepaired(2);
    // player.print_player_stats();
    // player.takeDamage(3);
    // player.print_player_stats();
    // player.attack("you");
    // player.print_player_stats();
    // player.attack("another enemy");
    // player.print_player_stats();
    // player.guardGate();
    // player.takeDamage(120);
    // player.print_player_stats();

    // ClapTrap enemy("Bocal");
    // enemy.print_player_stats();
    // enemy.attack("Bocal");
    // enemy.print_player_stats();
    // enemy.beRepaired(2);
    // enemy.print_player_stats();
    // enemy.takeDamage(3);
    // enemy.print_player_stats();
    // enemy.attack("you");
    // enemy.print_player_stats();
    // enemy.attack("another enemy");
    // enemy.print_player_stats();
    // enemy.takeDamage(12);
    // enemy.print_player_stats();
    
    return 0;
}
