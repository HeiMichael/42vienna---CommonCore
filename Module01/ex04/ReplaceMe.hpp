/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReplaceMe.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 13:28:02 by miheider          #+#    #+#             */
/*   Updated: 2024/09/13 11:10:46 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACEME_H
#define REPLACEME_H

#include <string>
#include <iostream>
#include <fstream>

class ReplaceMe {
private:
    std::string     _filename; 
    std::string     _old_string;
    std::string     _new_string;
    std::ifstream   _old_file;
    std::ofstream   _new_file;

public:
    ReplaceMe(const std::string filename, const std::string old_string, const std::string new_string);
    ~ReplaceMe();
    
    int open_old_file();
    int create_and_open_new_file();
    int copy_and_replace();    
};

#endif

