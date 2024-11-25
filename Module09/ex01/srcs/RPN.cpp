/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:52:52 by miheider          #+#    #+#             */
/*   Updated: 2024/10/22 15:02:48 by miheider         ###   ########.fr       */
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
    if (first > 0 && second > 0) {
        return first > std::numeric_limits<double>::max() - second;
    }
    if (first < 0 && second < 0) {
        return first < -std::numeric_limits<double>::max() - second;
    }
    return false; // No overflow for mixed signs
}

bool multiply_overflow(double first, double second) {
    if (first == 0 || second == 0) {
        return false;  // No overflow with multiplication by zero
    }

    double abs_first = fabs(first);
    double abs_second = fabs(second);

    if (abs_first > std::numeric_limits<double>::max() / abs_second) {
        return true;  // Overflow will occur
    }

    return false;  // No overflow
}

int	convert_to_integer(char *input) {
	int	res;
	
	std::stringstream rss(input);
	rss >> res;
	return res;
}

int	check_input(char *word) {
	int sign = 0;
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
		for (int i = 0; word[i]; i++) {
			if (word[0] == '-' && strlen(word) > 1) {
				sign = 1;
				continue;
			}
			if (isdigit(word[i])) {
				continue;
			} else if (word[i] == '\0') {
				return 0;
			} else {
				throw RPN::InvalidInputException();
			}
		}
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
	word = strtok(input, " ");
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
					throw RPN::InvalidInputException();		//overflow
				}
				calc.push(second + first);
			} else if (res == 2) {
				calc.push(second - first);
			} else if (res == 3) {
				if (multiply_overflow(first, second)) {
					std::cout << "!!!!!!!!" << std::endl;
					throw RPN::InvalidInputException();		//overflow
				}
				calc.push(second * first);
			} else {
				if (first == 0)
					throw DivisionByZeroException();
				else
					calc.push(second / first);
			}	
		}
		word = strtok(NULL, " ");
	}
	if ((num - 1) == op)
		return calc.top();
	else
		throw RPN::InvalidNumberInputException();
}

const char * RPN::InvalidNumberInputException::what() const throw() {
    return "Invalid input.";
}

const char * RPN::InvalidInputException::what() const throw() {
    return "Too much/less arguments.";
}

const char * RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero";
}
