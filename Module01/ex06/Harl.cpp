/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:20:07 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 13:03:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain( std::string level ) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;
    
    for (i = 0; i < (int)(sizeof(levels) / sizeof(levels[0])); i++) {
        if (level == levels[i])
            break; 
    }
    
    std::cout << "[ " << level << " ]" << std::endl;
    
    switch (i) {
        case 0:
            _debug();
        case 1:
            _info();
        case 2:
            _warning();
        case 3: {
            _error();
            break;
        }
        default:
            std::cout << "This error is an error." << std::endl;
    }
}

void Harl::_debug( void ) {
    std::cout << "1) I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-specialketchup burger. "
        "I really do!" << std::endl;
}

void Harl::_info( void ) {
    std::cout << "2) I cannot believe adding extra bacon costs more "
        "money. You didn’t put enough bacon in my burger! If you "
        "did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning( void ) {
    std::cout << "3) I think I deserve to have some extra bacon for "
        "free. I’ve been coming for years whereas you started "
        "working here since last month." << std::endl;
}

void Harl::_error( void ) {
    std::cout << "4) This is unacceptable! I want to speak to the "
        "manager now." << std::endl;
}
