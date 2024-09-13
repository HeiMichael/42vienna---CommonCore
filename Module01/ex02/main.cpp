/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:49:22 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:13:44 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main (void) {
    std::string test = "HI THIS IS BRAIN";
    std::string *stringPTR = &test;
    std::string &stringREF = test;
    
    std::cout << "memory address of the string variable: " << &test << std::endl;
    std::cout << "memory address held by stringPTR     : " << stringPTR << std::endl;
    std::cout << "memory address held by stringREF     : " << &stringREF << std::endl;

    std::cout << "value of the string variable         : " << test << std::endl;
    std::cout << "value pointed to by stringPTR        : " << *stringPTR << std::endl;
    std::cout << "value pointed to by stringREF        : " << stringREF << std::endl;

    
    //std::string &anotherREF;            //error: Reference must be initialized when declared
    //&anotherREF = test;
    //std::cout << "value of the string variable         : " << &anotherREF << std::endl;

    //std::string str = "JUST DO IT";
    //std::string &stringREF = str;       //error: Reference cannot be reassigned

    //std::string &lastREF = test;
    //lastREF = "WHAT IS GOING ON?";      //Reference provide a direct way to access a variable without using defreferencing operator ('*') -> easier syntax
    //std::cout << "value of the string variable         : " << test << std::endl;
    
    return 0;
}
