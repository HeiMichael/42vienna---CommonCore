/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:52:52 by miheider          #+#    #+#             */
/*   Updated: 2024/12/09 12:54:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
    //std::cout << "Default constructor (RPN) called" << std::endl;
}

RPN::~RPN() {
    //std::cout << "Destructor (RPN) called" << std::endl;
}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        _rev_polish_calculator = other._rev_polish_calculator;
    }
    return *this;
}

bool add_overflow(double first, double second) {
    double result = first + second;
    return result > MAX_VALUE || result < MIN_VALUE;
}

bool multiply_overflow(double first, double second) {
    double result = first * second;
    return result > MAX_VALUE || result < MIN_VALUE;
}

bool subtr_overflow(double first, double second) {
	double result = first - second;
	return result > MAX_VALUE || result < MIN_VALUE;
}

int convert_to_integer(char *input) {
    char *end;
    long res = strtol(input, &end, 10);
    if (*end != '\0' || res > MAX_VALUE || res < MIN_VALUE) {
        throw RPN::OverflowException();
    }
    return static_cast<int>(res);
}

int check_input(char *word) {
    if (strlen(word) == 1) {
        if (word[0] == '+')
            return 1;
        else if (word[0] == '-')
            return 2;
        else if (word[0] == '*')
            return 3;
        else if (word[0] == '/')
            return 4;
        else if (isdigit(word[0]))
            return 0;
        else
            throw RPN::InvalidInputException();
    } else {
        char *end;
        long res = std::strtol(word, &end, 10);
        if (*end != '\0') {
			throw RPN::InvalidNumberInputException();
        }
		if (res > INT_MAX || res < INT_MIN)
			throw RPN::OverflowException();
    }
    return 0;
}

double RPN::calculate(char* input) {
    std::stack<double>	calc;
	std::string ret = "\0";
	char* word = NULL;
	size_t	num = 0;
	size_t	op = 0;

	if (!input || !*input) {
		throw RPN::InvalidInputException();
	}
	word = std::strtok(input, " ");
	while (word != NULL) {
		int res = check_input(word);
		if (res == 0) {
			num++;
			calc.push(convert_to_integer(word));
		} else {
			op++;
			if (calc.size() < 2) {
				throw RPN::InvalidInputException();
			}
			double first = calc.top();
			calc.pop();
			double second = calc.top();
			calc.pop();
			if (res == 1) {
				if (add_overflow(first, second)) {
					throw RPN::OverflowException();
				}
				calc.push(second + first);
			} else if (res == 2) {
				if (subtr_overflow(first, second)) {
					throw RPN::OverflowException();
				}
				calc.push(second - first);
			} else if (res == 3) {
				if (multiply_overflow(first, second)) {
					throw RPN::OverflowException();
				}
				calc.push(second * first);
			} else {
				if (first == 0)
					throw DivisionByZeroException();
				else
					calc.push(second / first);
			}	
		}
		word = std::strtok(NULL, " ");
	}
	if ((num - 1) == op) {
		double result = calc.top();
		if (std::fmod(result, 1.0) == 0.0) {
            std::cout << std::fixed << std::setprecision(0) << result << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(2) << result << std::endl;
        }		return result;
	} else {
		throw RPN::InvalidNumberInputException();
	}
}

const char * RPN::InvalidNumberInputException::what() const throw() {
    return "Invalid input";
}

const char * RPN::InvalidInputException::what() const throw() {
    return "Invalid arguments";
}

const char * RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero";
}

const char * RPN::OverflowException::what() const throw() {
	return "Number too high/low";
}
