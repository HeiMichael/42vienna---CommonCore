/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:04:44 by miheider          #+#    #+#             */
/*   Updated: 2024/08/22 15:00:34 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include<iostream>


int main ()
{
    PhoneBook   myPhone;
    std::string input;

    while (!std::cin.eof()) {
        std::cout << "Enter ADD, SEARCH or EXIT" << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof())
            return 0;
        if (input == "ADD") {
            myPhone.add();
        }
        else if (input == "SEARCH") {
            myPhone.search();
        }
        else if (input == "EXIT") {
            std::cout << "All data will be irrevocably deleted. Good bye!" << std::endl;
            return 0;
        }
        else
            std::cout << "worng input. Please enter 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
    }
    return 0;
}
