/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:59:00 by miheider          #+#    #+#             */
/*   Updated: 2024/10/12 12:43:14 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    std::cout << "Default Constructor (ScalarConverter) called" << std::endl;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "Destructor (ScalarConverter) called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    std::cout << "Copy constructor (ScalarConverter) called" << std::endl;
	*this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    std::cout << "Copy assignment operator (ScalarConverter) called" << std::endl;
    if (this != &other) {
        return *this;
    }
    return *this;
}

void	input_is_char(std::string& input) {
	std::cout << "CHARACTER" << std::endl;
	std::cout << std::endl;
	char ct_char = '\0';
	if (input.length() == 1) {
        ct_char = input[0];
	}
	int ct_int = static_cast<int>(ct_char);
	float ct_float = static_cast<float>(ct_char);
	double ct_double = static_cast<double>(ct_char);

	std::cout << "Char:\t" << ct_char << std::endl;
	std::cout << "Int:\t" << ct_int << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float:\t" << ct_float << "f" << std::endl;
	std::cout << "Double:\t" << ct_double << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void	input_is_int(std::string input) {
	if (input.length() > 11)
		throw (std::overflow_error("Overflow detected"));
	std::cout << "INTEGER" << std::endl;
	std::cout << std::endl;
	int ct_int;
    std::istringstream iss(input);
    iss >> ct_int;
	
	char ct_char;
	if (ct_int >= 33 && ct_int <= 126) {
		ct_char = static_cast<char>(ct_int);
		std::cout << "Char:\t'" << ct_char << "'" << std::endl;
	} else if ((ct_int >= 0 && ct_int <= 32) || ct_int == 127) {
		std::cout << "Char:\tnot displayable" << std::endl;
	} else {
		std::cout << "Char:\timpossible" << std::endl;
	}
		
	float ct_float = static_cast<float>(ct_int);
	double ct_double = static_cast<double>(ct_int);

	std::cout << "Int:\t" << ct_int << std::endl;
	std::cout << std::fixed << std::setprecision(1);
    std::cout << "Float:\t" << ct_float << "f" << std::endl;
    std::cout << "Double:\t" << ct_double << std::endl;
    std::cout.unsetf(std::ios::fixed);
}

void	input_is_float(std::string input) {
	std::cout << "FLOAT" << std::endl;
	std::cout << std::endl;

	bool dot;
	float ct_float;
	std::istringstream iss(input);
	iss >> ct_float;

	std::ostringstream oss;
    oss << ct_float;
    std::string converted_str = oss.str();

    if (converted_str.find('.') != std::string::npos) {
        dot = true;
    } else {
        dot = false;
    }

	char ct_char;
	if (ct_float >= 33 && ct_float <= 126) {
		ct_char = static_cast<char>(ct_float);
		std::cout << "Char:\t'" << ct_char << "'" << std::endl;
	} else if ((ct_float >= 0 && ct_float <= 32) || ct_float == 127) {
		std::cout << "Char:\tnot displayable" << std::endl;
	} else {
		std::cout << "Char:\timpossible" << std::endl;
	}	
	int ct_int = static_cast<int>(ct_float);
	double ct_double = static_cast<double>(ct_float);

	std::cout << "Int:\t" << ct_int << std::endl;
	if (dot == true) {
		std::cout << "Float:\t" << ct_float << "f" << std::endl;
		std::cout << "Double:\t" << ct_double << std::endl;
	} else {
		std::cout << "Float:\t" << ct_float << ".0f" << std::endl;
		std::cout << "Double:\t" << ct_double << ".0" << std::endl;
	}
}

void	input_is_double(std::string input) {
	std::cout << "DOUBLE" << std::endl;
	std::cout << std::endl;

	bool dot;
	double ct_double;
	std::istringstream iss(input);
	iss >> ct_double;

	std::ostringstream oss;
    oss << ct_double;
    std::string converted_str = oss.str();

    if (converted_str.find('.') != std::string::npos) {
        dot = true;
    } else {
        dot = false;
    }

	char ct_char;
	if (ct_double >= 33 && ct_double <= 126) {
		ct_char = static_cast<char>(ct_double);
		std::cout << "Char:\t'" << ct_char << "'" << std::endl;
	} else if ((ct_double >= 0 && ct_double <= 32) || ct_double == 127) {
		std::cout << "Char:\tnot displayable" << std::endl;
	} else {
		std::cout << "Char:\timpossible" << std::endl;
	}	
	int ct_int = static_cast<int>(ct_double);
	float ct_float = static_cast<float>(ct_double); 

	std::cout << "Int:\t" << ct_int << std::endl;
    if (dot == true) {
        std::cout << "Float:\t" << ct_float << "f" << std::endl;
    } else {
        std::cout << "Float:\t" << ct_float << ".0f" << std::endl;
    }
    std::cout << std::fixed << std::setprecision(15);
    std::cout << "Double:\t" << ct_double << std::endl;
}

void input_is_pseudo(std::string input) {
	std::cout << "PSEUDO LITERAL" << std::endl;
	std::cout << std::endl;
	std::cout << "Char:\timpossible" << std::endl;
	std::cout << "Int:\timpossible" << std::endl;
	if (input == "nan" || input == "-inf" || input == "+inf") {
		std::cout << "Float:\t" << input << "f" << std::endl;
		std::cout << "Double:\t" << input << std::endl; 
	} else {
		std::cout << "Float:\t" << input << std::endl;
		std::cout << "Double:\t" << input.substr(0, input.length() - 1) << std::endl;
	}
}

bool isDouble(const std::string& str) {
	if (str.find('.') == false)
		return false;
	std::istringstream iss(str);
    double value;
    if (!(iss >> value)) {
        return false;
    }
    return iss.eof();
}

bool isInteger(const std::string& str) {
	std::istringstream iss(str);
    long temp;
    iss >> temp;

    if (temp > std::numeric_limits<int>::max() || temp < std::numeric_limits<int>::min()) {
        throw (std::overflow_error("Overflow detected"));
    }
	
	std::istringstream jss(str);
    int value;
    if (!(jss >> value)) {
        return false;
    }
    return jss.eof();
}

bool isFloat(const std::string& str) {
	if (str.length() < 4)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	if (str.find('.') == false)
		return false;
	std::string floatPart = str.substr(0, str.length() - 1);
	std::istringstream iss(floatPart);
    float value;
    if (!(iss >> value)) {
        return false;
    }
    return iss.eof();
}

bool isPseudoLiteral(const std::string& str) {
	if (str == "-inf" || str == "+inf" || str == "nan"
		|| str == "-inff" || str == "+inff" || str == "nanf")
		return true;
	return false;
}

void ScalarConverter::convert(std::string to_convert) {
    if (isInteger(to_convert)) {
        input_is_int(to_convert);
    } else if (isFloat(to_convert)) {
		input_is_float(to_convert);
    } else if (isDouble(to_convert)) {
        input_is_double(to_convert);
    } else if (isPseudoLiteral(to_convert)) {
		input_is_pseudo(to_convert);
	} else {
		input_is_char(to_convert);
	}
}
