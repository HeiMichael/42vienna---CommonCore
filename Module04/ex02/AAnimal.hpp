/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 10:41:54 by miheider          #+#    #+#             */
/*   Updated: 2024/09/24 11:02:43 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string _type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal& operator=(const AAnimal& other);

        virtual void        makeSound(void) const = 0;
        virtual std::string getType(void) const;
};
