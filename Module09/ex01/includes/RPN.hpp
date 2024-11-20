/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:17:26 by miheider          #+#    #+#             */
/*   Updated: 2024/10/22 15:02:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <limits>
#include <cmath>

class RPN {
    private:
        std::stack<double>  _rev_polish_calculator;
    public:
        RPN();
        ~RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        
        double    calculate(char *input);

        class InvalidNumberInputException : std::exception {
            public:
                const char * what() const throw();
        };
        class InvalidInputException : std::exception {
            public:
                const char * what() const throw();
        };
        class DivisionByZeroException : std::exception {
            public:
                const char * what() const throw();
        };
};
