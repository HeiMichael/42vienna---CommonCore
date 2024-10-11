/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:55:57 by miheider          #+#    #+#             */
/*   Updated: 2024/09/26 08:22:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        std::cout << "-----------------------------------------" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
    
        ICharacter* me = new Character("me");
    
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
    
        ICharacter* bob = new Character("bob");
    
        me->use(0, *bob);
        me->use(1, *bob);
    
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
    
        ICharacter* me = new Character("me");
    
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
    
        ICharacter* bob = new Character("bob");
        std::cout << "++++++++++++++++++++++++" << std::endl;
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        me->use(4, *bob);

        me->unequip(1);

        std::cout << "++++++++++++++++++++++++" << std::endl;
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);

        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        std::cout << "++++++++++++++++++++++++" << std::endl;
        me->use(0, *bob);
        me->use(1, *bob);
        me->use(2, *bob);
        me->use(3, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    {
        std::cout << std::endl;
        std::cout << "--------------Deep Copy------------------" << std::endl;
        ICharacter* original = new Character("Original");

        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        AMateria* tmp;
        tmp = src->createMateria("ice");
        original->equip(tmp);
        tmp = src->createMateria("cure");
        original->equip(tmp);

        std::cout << "Original character equipped with ice and cure." << std::endl;
    
        //Copy the original character using the copy constructor
        ICharacter* copy = new Character(*dynamic_cast<Character*>(original));
        std::cout << "Copy of original character created." << std::endl;

        //Modify the original character and see if the copy is affected
        original->unequip(0); 
        std::cout << "Original character unequipped ice." << std::endl;

        std::cout << "Using original character:" << std::endl;
        original->use(0, *original);			//Should not use anything
        original->use(1, *original);			//Should use "cure"

        std::cout << "Using copy character:" << std::endl;
        copy->use(0, *copy);					//Should still have "ice" equipped and use it
        copy->use(1, *copy);					//Should use "cure"

        //Modify the copy and ensure the original is unaffected
        copy->unequip(1);						//Unequip "cure" from the copied character
        std::cout << "Copy character unequipped cure." << std::endl;

        std::cout << "Using original character after modifying the copy:" << std::endl;
        original->use(1, *original);			//Original should still have "cure" equipped

        std::cout << "Using copy character after modifying the copy:" << std::endl;
        copy->use(1, *copy);					//Copy should not use "cure" because it was unequipped

        delete original;
        delete copy;
        delete src;
    }
    return 0;
}
