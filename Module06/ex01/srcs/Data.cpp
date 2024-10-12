/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:19:36 by miheider          #+#    #+#             */
/*   Updated: 2024/10/05 12:19:29 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {
    
}

Data::~Data() {

}

Data::Data(const Data& other) {
    *this = other;
}

Data& Data::operator=(const Data& other) {
    if (this != &other)
        return *this;
    return *this;
}
