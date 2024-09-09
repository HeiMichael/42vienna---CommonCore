/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:04:36 by miheider          #+#    #+#             */
/*   Updated: 2024/08/29 17:35:46 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

std::string    PhoneBook::_format_input(std::string text) const {
    if (text.length() > 10)
        return text.substr(0, 9) + ".";
    else
        return text;
} 

bool    PhoneBook::_is_ascii_value(std::string input) const {
    int i;

    for (i = 0; input[i]; i++) {
        if (input[i] < 32 || input[i] >= 127)
            return false;
    }
    return true;
}

bool    PhoneBook::_process_entries(std::string entry, std::string *saving) {
    std::cout << "Enter " << entry << ": " << std::endl;
    std::getline(std::cin, entry);
    if (std::cin.eof())
            return 0;
    if (entry == "\0" || !_is_ascii_value(entry)) {
        std::cout << "Error: Invalid input." << std::endl;
        return 0;
    }
    *saving = entry;
    return 1;
}

void    PhoneBook::add(void) {
    std::string first_name = "";
    std::string last_name = "";
    std::string nick_name = "";
    std::string number = "";
    std::string secret = "";
    static int  index;
    
    if (index > 7)
        std::cout << "Warning! Entry with index " << ((index % 8) + 1)
            << " will be overwritten." << std::endl;
    
    if (!_process_entries("first name", &first_name)
        || !_process_entries("last name", &last_name)
        || !_process_entries("nickname", &nick_name)
        || !_process_entries("phone number", &number)
        || !_process_entries("darkest secret", &secret))
        return ;

    _contacts[index % 8].set_index(index % 8);
    _contacts[index % 8].set_firstname(first_name);
    _contacts[index % 8].set_lastname(last_name);
    _contacts[index % 8].set_nickname(nick_name);
    _contacts[index % 8].set_number(number);
    _contacts[index % 8].set_secret(secret);
    index++;    
}

void    PhoneBook::search(void) {
    std::string index;
    int i = 0;
    char    c = '\0';
 
    if (_contacts[0].get_index() == "") {
        std::cout << "The Phonebook is empty." << std::endl;
        return ;
    }
    std::cout << "┏━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┯━━━━━━━━━━┓" << std::endl;
    while (i < 8) {
        if (_contacts[i].get_index() == "")
            break ;
        std::cout << "┃" << "         " << _contacts[i].get_index() << "│";
        std::cout << std::setw(10) << _format_input(_contacts[i].get_firstname()) << "│";
        std::cout << std::setw(10) << _format_input(_contacts[i].get_lastname()) << "│";
        std::cout << std::setw(10) << _format_input(_contacts[i].get_nickname()) << "┃" << std::endl;
        i++;
    }
    std::cout << "┗━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┷━━━━━━━━━━┛" << std::endl;
    std::cout << "Enter index: " << std::endl;
    std::getline(std::cin, index);
    if (std::cin.eof())
            return ;
    if (index.size() == 1 && index[0] >= '1' && index[0] <= (i + '0'))
        c = index[0] - 1;
    else if (index.size() == 1 && index[0] > (i + '0') && index[0] <= '8') {
        std::cout << "No entry at index " << index << std::endl;
        return ;
    }
    else {
        std::cout << "invalid index." << std::endl;
        return ;
    }
    std::cout << "Index: " << _contacts[c - '0'].get_index() << std::endl;
    std::cout << "First name: " << _contacts[c - '0'].get_firstname() << std::endl;
    std::cout << "Last name: " << _contacts[c - '0'].get_lastname() << std::endl;
    std::cout << "Nickname: " << _contacts[c - '0'].get_nickname() << std::endl;
    std::cout << "Phone number: " << _contacts[c - '0'].get_number() << std::endl;
    std::cout << "Darkest secret: " << _contacts[c - '0'].get_secret() << std::endl;
}

