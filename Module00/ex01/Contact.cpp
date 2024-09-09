/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 17:04:40 by miheider          #+#    #+#             */
/*   Updated: 2024/08/17 14:04:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

void	Contact::set_index(int index) {
	_index = index + '0' + 1;
}

void		Contact::set_lastname(std::string lastname) {
    _lastname = lastname;
}

void		Contact::set_firstname(std::string firstname) {
    _firstname = firstname;
}

void		Contact::set_nickname(std::string nickname) {
    _nickname = nickname;
}

void		Contact::set_number(std::string number) {
    _number = number;
}

void		Contact::set_secret(std::string secret) {
    _secret = secret;
}

std::string	Contact::get_lastname() const {
    return _lastname;
}

std::string	Contact::get_firstname() const {
    return _firstname;
}

std::string	Contact::get_nickname() const {
    return _nickname;
}

std::string	Contact::get_number() const {
    return _number;
}

std::string	Contact::get_secret() const {
    return _secret;
}

std::string	Contact::get_index() const {
	return _index;
}
