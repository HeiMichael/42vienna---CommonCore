/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 08:15:02 by miheider          #+#    #+#             */
/*   Updated: 2024/09/25 11:24:59 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource {
    private:
        AMateria*   _inventory[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource (const MateriaSource& other);
        MateriaSource& operator=(const MateriaSource& other);

        void        learnMateria(AMateria* m);
        AMateria*   createMateria(std::string const & type);
};
