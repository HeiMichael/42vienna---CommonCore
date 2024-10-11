/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:43:07 by miheider          #+#    #+#             */
/*   Updated: 2024/09/24 11:04:30 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        std::string _type;
        Brain*      _brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);

        void        makeSound(void) const;
        std::string getType(void) const;
        std::string get_ideas(int index) const;
        void        set_ideas(std::string message, int i);
};
