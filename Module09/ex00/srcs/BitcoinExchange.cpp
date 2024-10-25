/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:06:06 by miheider          #+#    #+#             */
/*   Updated: 2024/10/25 14:06:23 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

float	check_amount(std::string value) {
	std::stringstream	vss(value);
	float				number;

	if (!(vss >> number) || !vss.eof())
		throw BitcoinExchange::InvalidInputException();
	if (number < 0 || number > 1000)
		throw BitcoinExchange::ValueOutOfRangeException();


	return number;
}

bool	isleapyear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void	date_validation(std::string date) {
	std::stringstream dss(date);
	int year, month, day;

	dss >> year;
	dss.ignore();
	dss >> month;
	dss.ignore();
	dss >> day;
	if (year < 2009 || year > 2024 || month < 1 || month > 12 || day < 1 || day > 31)
		throw BitcoinExchange::InvalidDateInDataBaseException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::InvalidDateInDataBaseException();
	if (month == 2 && !isleapyear(year) && day > 28)
		throw BitcoinExchange::InvalidDateInDataBaseException();
	if (month == 2 && isleapyear(year) && day > 29)
		throw BitcoinExchange::InvalidDateInDataBaseException();
}

std::string	check_date(std::string date) {	
	if (date.length() != 10)
		throw BitcoinExchange::InvalidDateInDataBaseException();
	if (date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::InvalidDateInDataBaseException();
	for (int i = 0; date[i]; i++) {
		if (i == 4 || i == 7)
			continue;
		if (date[i] < 48 || date[i] > 57)
			throw BitcoinExchange::InvalidDateInDataBaseException();
	}
	date_validation(date);
	return date;
}

double check_value(std::string value) {
    std::stringstream   ess(value);
    double				price;

    if (!(ess >> price) || !ess.eof())
		throw BitcoinExchange::IncorrectValueInDatabaseException();
    return price;
}

BitcoinExchange::BitcoinExchange() {
    //std::cout << "Default constructor (BitcoinExchange) called" << std::endl;
    size_t              pos;
    std::string         line;
	std::ifstream 	    db("./data.csv");
    std::string         key;
    std::string         value;
	
	if (!db)
		throw CanNotOpenFileException();
	std::getline(db, line);
	while (std::getline(db, line)) {
        pos = line.find(',');
        if (pos != std::string::npos) {
            key = line.substr(0, pos);
            value = line.substr(pos + 1, line.length());
            _data_base[check_date(key)] = check_value(value);
        } else {
            throw InvalidDataBaseException();
        }
	}
}

BitcoinExchange::~BitcoinExchange() {
    //std::cout << "Destructor (bitcoinExchange) called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        return *this;
    return *this;
}

void	BitcoinExchange::bitcoin_calculator(std::string input) {
    size_t              pos;
    std::string         line;
	std::ifstream 	    btc_trade(input.c_str());
    std::string         key;
    std::string         value;
	
	if (!btc_trade)
		throw CanNotOpenFileException();
	std::getline(btc_trade, line);
	if (line != "date | value")
		throw InvalidInputFileException();
	while (std::getline(btc_trade, line)) {
		try {
			pos = line.find('|');
			if (pos != std::string::npos) {
				key = line.substr(0, pos - 1);
				value = line.substr(pos + 2, line.length());
				_amount[check_date(key)] = check_amount(value);
				std::cout << "Key:\t" << key << "\tValue:\t" << value << std::endl;
				} else {
					throw InvalidInputException();
				} 
			} catch (BitcoinExchange::InvalidInputException& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			} catch (BitcoinExchange::ValueOutOfRangeException& e) {
				std::cerr << "Error: " << e.what() << std::endl;
			}
	}
}

const char * BitcoinExchange::InvalidInputException::what() const throw() {
    return "Invalid Input";
}

const char * BitcoinExchange::CanNotOpenFileException::what() const throw() {
    return "Can not open file";
}

const char * BitcoinExchange::InvalidDataBaseException::what() const throw() {
    return "Invalid Database";
}

const char * BitcoinExchange::IncorrectValueInDatabaseException::what() const throw() {
	return "Invalid share price in Database";
}

const char * BitcoinExchange::InvalidDateInDataBaseException::what() const throw() {
	return "Invalid Date in Database";
}

const char * BitcoinExchange::InvalidInputFileException::what() const throw() {
	return "Invalid input file header";
}

const char * BitcoinExchange::ValueOutOfRangeException::what() const throw() {
	return "Value is out of range. expected between 0 - 1000";
}



