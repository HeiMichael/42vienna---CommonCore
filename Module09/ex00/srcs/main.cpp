/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:57:50 by miheider          #+#    #+#             */
/*   Updated: 2024/12/09 10:36:26 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void close_all_fds() {
    for (int fd = 3; fd < 1024; ++fd) {
        close(fd);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error:\nInvalid Input (number of arguments)" << std::endl;
        return 1;
    }
    try {
        BitcoinExchange broker;
            broker.bitcoin_calculator(argv[1]);
    } catch (BitcoinExchange::CanNotOpenFileException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::InvalidDataBaseException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::IncorrectValueInDatabaseException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::InvalidDateInDataBaseException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::InvalidInputFileException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::InvalidFormatInDataBaseException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    } catch (BitcoinExchange::InvalidInputException& e) {
        std::cerr << "Error:\n" << e.what() << std::endl;
    }
    close_all_fds();
    return 0;
}
