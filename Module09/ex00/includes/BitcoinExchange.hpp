/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:05:59 by miheider          #+#    #+#             */
/*   Updated: 2024/12/09 10:34:40 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <map>
#include <fstream>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <unistd.h>

class BitcoinExchange {
    private:
		std::map<std::string, double>	_data_base;

    public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void	find_data(const std::string& date, double amount);
		void	bitcoin_calculator(std::string input);

    class InvalidInputException : std::exception {
        public:
            const char * what() const throw();
    };
	class CanNotOpenFileException : std::exception {
		public:
			const char * what() const throw();
	};
	class InvalidDataBaseException : std::exception {
		public:
			const char * what() const throw();
	};
	class IncorrectValueInDatabaseException : std::exception {
		public:
			const char * what() const throw();
	};
	class InvalidFormatInDataBaseException : std::exception {
		public:
			const char * what() const throw();
	};
	class InvalidDateInDataBaseException : std::exception {
		public:
			const char * what() const throw();
	};
	class InvalidInputFileException : std::exception {
		public:
			const char * what() const throw();
	};
	class ValueOutOfRangeException : std::exception {
		public:
			const char * what() const throw();
	};
};

