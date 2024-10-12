/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:30:39 by miheider          #+#    #+#             */
/*   Updated: 2024/10/12 13:12:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
    
    std::srand(static_cast<unsigned int>(std::time(0)));
    int random_number = std::rand() % 3;
    
    if (random_number == 0) {
        std::cout << "Class A was generated" << std::endl;
        return new A;
    } else if (random_number == 1) {
        std::cout << "Class B was generated" << std::endl;
        return new B;
    } else if (random_number == 2) {
        std::cout << "Class C was generated" << std::endl;
        return new C;

    } else {
        std::cout << "Nothing was generated" << std::endl;
    }
    return NULL;
}

/*if a cast fails (because the two derived classes are not related) dynamic_cast returns
a nullptr*/
void identify(Base* p) {
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);
    
    std::cout << std::endl;
    if (a != NULL) {
        std::cout << "It is an object of the A class" << std::endl;
    } else if (b != NULL) {
        std::cout << "It is an object of the B class" << std::endl;
    } else if (c != NULL) {
        std::cout << "It is an object of the C class" << std::endl;
    }
    std::cout << std::endl;
}

/*dynamic cast with references is not recommended, if cast fails dynamic_cast 
throws an exception (bad_cast)*/
void identify(Base& p) {
    try {
        A &a = dynamic_cast<A &>(p);
        (void) a;
        std::cout << "It's an A class object" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Failed to cast to class A: " << e.what() << std::endl;
    }
    try {
        B &b = dynamic_cast<B &>(p);
        (void) b;
        std::cout << "It's an B class object" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Failed to cast to class B: " << e.what() << std::endl;
    }
    try {
        C &c = dynamic_cast<C &>(p);
        (void) c;
        std::cout << "It's an C class object" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Failed to cast to class C: " << e.what() << std::endl;
    }    
}

int main(void) {
    Base* a;
    a = generate();
    identify(a);
    identify(*a);
    delete a;
}
