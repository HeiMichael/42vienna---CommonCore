/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:15:43 by miheider          #+#    #+#             */
/*   Updated: 2024/10/12 13:08:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>


int main() {
    Data* ptr = new Data;
    uintptr_t test = 0;

    ptr->_test = "Nice evaluation so far";
    std::cout << "Before serialization:\t" << ptr->_test << std::endl;
    std::cout << "Before serialization:\t" << ptr << std::endl;
    std::cout << std::endl;
    test = Serializer::serialize(ptr);
    std::cout << "After serialization:\t" << test << std::endl;
    std::cout << "After serialization:\t" << &test << std::endl;
    std::cout << std::endl;
    ptr = Serializer::deserialize(test);
    std::cout << "After deserialization:\t" << ptr->_test << std::endl;
    std::cout << "After deserialization:\t" << ptr << std::endl;
    delete ptr;

    return 0;
}
