/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:50:05 by miheider          #+#    #+#             */
/*   Updated: 2024/09/25 10:11:17 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();                                     //Default constructor
        virtual ~AMateria();                            //Destructor
        AMateria(const AMateria& other);                //Copy Constructor
        AMateria& operator=(const AMateria& other);     //Copy Assignment Constructor
        AMateria(std::string const & type);

        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
