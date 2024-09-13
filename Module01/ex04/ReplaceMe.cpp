/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceMe.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:27:43 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 11:10:38 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReplaceMe.hpp"

ReplaceMe::ReplaceMe(const std::string filename, const std::string old_string, const std::string new_string) {
    _filename = filename;
    _old_string = old_string;
    _new_string = new_string;
}

ReplaceMe::~ReplaceMe() {
    if (_old_file.is_open())
        _old_file.close();
    if (_new_file.is_open())
        _new_file.close();
}

int ReplaceMe::open_old_file() {
    _old_file.open(_filename.c_str(), std::ios::in);
    if (!_old_file) {
        std::cerr << "Error: could not open the file." << std::endl;
        return 1;
    }
    return 0;
}

int ReplaceMe::create_and_open_new_file() {
    std::string new_filename;
    
    new_filename = _filename + ".replace";
    _new_file.open(new_filename.c_str(), std::ios::out);
    if (!_new_file) {
        std::cerr << "Error: could not create file " << new_filename << std::endl;
        return 1;
    }
    return 0;
}

int ReplaceMe::copy_and_replace() {
    size_t pos;
    std::string old_line;

    while (std::getline(_old_file, old_line)) {
        pos = old_line.find(_old_string);
        while (pos != std::string::npos) {
            old_line.erase(pos, _old_string.length());
            old_line.insert(pos, _new_string);
            pos = old_line.find(_old_string, pos + _new_string.length()); // Move position forward
        }
        _new_file << old_line << std::endl;
    }
    return 0;
}
