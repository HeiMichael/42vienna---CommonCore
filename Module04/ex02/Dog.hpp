/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:40:30 by miheider          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:35 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

class Dog : public AAnimal {
    private:
        std::string _type;
        Brain*      _brain;
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);

        void        makeSound(void) const;
        std::string getType(void) const;
        std::string get_ideas(int index) const;
        void        set_ideas(std::string message, int i);
};
