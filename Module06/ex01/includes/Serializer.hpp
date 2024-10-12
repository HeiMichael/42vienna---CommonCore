/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:14:22 by miheider          #+#    #+#             */
/*   Updated: 2024/10/05 12:19:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Data.hpp"
#include <cstddef>
#include <stdint.h>

class Serializer {
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
    public:
        static uintptr_t serialize(Data* ptr); //It takes a pointer and converts it to the unsigned integer type uintptr_t.
        static Data* deserialize(uintptr_t raw); //It takes an unsigned integer parameter and converts it to a pointer to Data.
};
