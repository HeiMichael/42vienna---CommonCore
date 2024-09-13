/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:20:07 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 13:06:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::complain( std::string level ) {
    void (Harl::*ptr_to_memfn[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < (int)(sizeof(levels) / sizeof(levels[0])); i++) {
        if (level == levels[i]) {
            (this->*ptr_to_memfn[i])();
            return;
        }
    }
    std::cout << "Error: no suitable level." << std::endl;
}

void Harl::_debug( void ) {
    std::cout << "[ DEBUG ]: I love having extra bacon for my "
        "7XL-double-cheese-triple-pickle-specialketchup burger. "
        "I really do!" << std::endl;
}

void Harl::_info( void ) {
    std::cout << "[ INFO ]: I cannot believe adding extra bacon costs more "
        "money. You didn’t put enough bacon in my burger! If you "
        "did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::_warning( void ) {
    std::cout << "[ WARNING]: I think I deserve to have some extra bacon for "
        "free. I’ve been coming for years whereas you started "
        "working here since last month." << std::endl;
}

void Harl::_error( void ) {
    std::cout << "[ ERROR ]: This is unacceptable! I want to speak to the "
        "manager now." << std::endl;
}
