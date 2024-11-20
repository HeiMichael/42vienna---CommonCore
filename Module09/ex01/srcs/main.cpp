/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:31:04 by miheider          #+#    #+#             */
/*   Updated: 2024/10/22 13:55:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//#include <iostream>

int main (int argc, char **argv) {
    try{
        if (argc != 2) {
            throw RPN::InvalidNumberInputException();
        } else {
            RPN test;
            std::cout << test.calculate(argv[1]) << std::endl;
        } 
    } catch (const std::exception& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (const RPN::InvalidNumberInputException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (const RPN::InvalidInputException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (const int num) {
        std::cout << num << std::endl;
    } catch (const RPN::DivisionByZeroException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    }
    return 0;
}
