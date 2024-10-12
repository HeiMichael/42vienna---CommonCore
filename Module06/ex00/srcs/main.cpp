/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:59:49 by miheider          #+#    #+#             */
/*   Updated: 2024/10/04 12:46:40 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <exception>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error\nInvalid input" << std::endl;
        return 1;
    }
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception &e) {
        std::cerr << "Error\n" << e.what() << std::endl;
    }

    return 0;
}
