/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:47 by miheider          #+#    #+#             */
/*   Updated: 2024/09/25 13:36:23 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Cure : public AMateria {
    public:
        Cure();
        ~Cure();
        Cure (const Cure& other);
        Cure& operator=(const Cure& other);

        AMateria* clone() const;
        void use(ICharacter& target);
        std::string getType( void ) const;

};
