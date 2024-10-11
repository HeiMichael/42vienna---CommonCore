/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:14:53 by miheider          #+#    #+#             */
/*   Updated: 2024/09/25 13:36:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        Ice (const Ice& other);
        Ice& operator=(const Ice& other);

        std::string getType( void ) const;
        AMateria* clone() const;
        void use(ICharacter& target);
};
