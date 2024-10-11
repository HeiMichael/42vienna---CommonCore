/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:59 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 07:32:32 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    // std::cout << "Default constructor (MateriaSource) called" << std::endl;
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    // std::cout << "Destructor (MateriaSource) called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL) {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
}

MateriaSource::MateriaSource (const MateriaSource& other) {
    // std::cout << "Copy constructor (MateriaSource) called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i] != NULL) {
            this->_inventory[i] = other._inventory[i]->clone();            
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    // std::cout << "Copy assignment operator (MateriaSource) called" << std::endl;
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL)
            delete _inventory[i];
        if (other._inventory[i])
			this->_inventory[i] = (other._inventory[i])->clone();
	}
	return (*this);
}

void        MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return ;
        
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] == NULL) {
            _inventory[i] = m->clone();
            delete m;
            return ;
        }
    }
    std::cout << "inventory full" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (_inventory[i] != NULL) {
            if (_inventory[i]->getType() == type) {
                return _inventory[i]->clone();
            }
        }
    }
    return NULL;
}
