/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:19:41 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 13:33:30 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
std::ostream    &operator<<(std::ostream &ostream, Bureaucrat &print);

int main() {
    {
        std::cout << "--------------------     Test00     --------------------" << std::endl;
        std::cout << "first basic test to show the program is running \ncorrectly when no exception needs to be thrown" << std::endl;
        std::cout << std::endl;
        try {
            Bureaucrat test("Michi", 5);
            std::cout << test << std::endl;
            test.decrementGrade();
            std::cout << test << std::endl;
            test.incrementGrade();
            std::cout << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test01     --------------------" << std::endl;
        std::cout << "create bureaucrat \"Nicol\" with grade < 150" << std::endl;
        std::cout << std::endl;

        try {
            Bureaucrat test("Nicol", 152);
            std::cout << test << std::endl;
            Bureaucrat not_created("Jakob", 45);
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test02     --------------------" << std::endl;
        std::cout << "create bureaucrat \"Nicol\" with grade 0" << std::endl;
        std::cout << std::endl;
        
        try {
            Bureaucrat test("Nicol", 0);
            std::cout << test << std::endl;
            Bureaucrat not_created("Jakob", 45);
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test03     --------------------" << std::endl;
        std::cout << "create bureaucrat \"Nicol\" with grade 2 and\nincrement twice" << std::endl;
        std::cout << std::endl;
        
        try {
            Bureaucrat test("Nicol", 2);
            std::cout << test << std::endl;
            test.incrementGrade();
            std::cout << test << std::endl;
            test.incrementGrade();
            std::cout << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test04     --------------------" << std::endl;
        std::cout << "create bureaucrat without a parameter\nand decrement once" << std::endl;
        std::cout << std::endl;
        
        try {
            Bureaucrat test;
            std::cout << test << std::endl;
            test.decrementGrade();
            std::cout << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test05     --------------------" << std::endl;
        std::cout << "create bureaucrat \"Chris\" with grade 50 and incrementing 10 times\nthen decrementing by 20." << std::endl;
        std::cout << std::endl;
        
        try {
            Bureaucrat test("Chris", 50);
            std::cout << test << std::endl;
            for (int i = 0; i < 10; i++)
                test.incrementGrade();
            std::cout << test << std::endl;
            for (int i = 0; i < 20; i++)
                test.decrementGrade();
            std::cout << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test06     --------------------" << std::endl;
        std::cout << "create bureaucrat \"Chris\" with grade 135 and decrementing 20 times\n(will throw an exception) then incrementing by 10." << std::endl;
        std::cout << std::endl;
        
        try {
            Bureaucrat test("Chris", 135);
            std::cout << test << std::endl;
            for (int i = 0; i < 20; i++)
                test.decrementGrade();
            std::cout << test << std::endl;
            for (int i = 0; i < 10; i++)
                test.incrementGrade();
            std::cout << test << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
