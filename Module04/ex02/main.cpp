/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:38:31 by miheider          #+#    #+#             */
/*   Updated: 2024/09/24 11:03:07 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

#define ANIMALS 10

int main()
{
    {
        std::cout << "---------------------     Test0     ---------------------" << std::endl;
        //AAnimal j; not allowed!!!
        Dog k;
        Cat l;
    }
    {
        std::cout << std::endl;
        std::cout << "---------------------     Test1     ---------------------" << std::endl;
        const AAnimal* test[ANIMALS];
    
        for (int k = 0; k < ANIMALS; k++) {
            if (k % 2 == 0) {
                test[k] = new Dog;
                test[k]->makeSound();
                std::cout << test[k]->getType() << std::endl;
            }
            else {
                test[k] = new Cat;
                test[k]->makeSound();
                std::cout << test[k]->getType() << std::endl;
            }
            std::cout << std::endl;
        }

        for (int k = 0; k < ANIMALS; k++) {
            delete test[k];
        }
    }
    {
        std::cout << std::endl;
        std::cout << "---------------------     Test2     ---------------------" << std::endl;
        Dog* dog = new Dog;
        Cat* cat = new Cat;

        std::cout << "idea dog: " << dog->get_ideas(4) << std::endl;
        std::cout << "idea cat: " << cat->get_ideas(99) << std::endl;

        delete dog;
        delete cat; 
    }
    {
        std::cout << std::endl;
        std::cout << "---------------------     Test3     ---------------------" << std::endl;
        Dog* one = new Dog;
        Dog* two = new Dog(*one);

        std::cout << "idea one before: " << one->get_ideas(4) << std::endl;
        std::cout << "idea two before: " << two->get_ideas(4) << std::endl;

        one->set_ideas("Nicol", 4);

        std::cout << "idea one after: " << one->get_ideas(4) << std::endl;
        std::cout << "idea two after: " << two->get_ideas(4) << std::endl;

        delete one;

        std::cout << "idea two after: " << two->get_ideas(4) << std::endl;

        delete two; 
    }
    
    return 0;
}
