/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:59:47 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 16:56:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ReplaceMe.hpp"

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Error: invalid input" << std::endl;
        return 1;
    }
    if (std::string(argv[2]).empty()) {
        std::cerr << "Error: string1 cannot be empty." << std::endl;
        return 1;
    }

    ReplaceMe exchange(argv[1], argv[2], argv[3]);
    
    if (exchange.open_old_file()
        || exchange.create_and_open_new_file()
        || exchange.copy_and_replace()) {
        return 1;
    }

    return 0;
}
