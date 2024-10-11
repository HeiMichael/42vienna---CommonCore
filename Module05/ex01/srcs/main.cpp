/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:19:41 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 11:41:18 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
std::ostream    &operator<<(std::ostream &ostream, Bureaucrat &print);
std::ostream    &operator<<(std::ostream &ostream, Form &print);

int main() {
    {
        std::cout << "--------------------     Test00     --------------------" << std::endl;
        std::cout << "basic test: Form throws an exception if grade is > 0 or < 150";
        std::cout << std::endl;
        
        try {
            Form a(2, 45);
            Form b(17, 245);
            Form c(0, 45);
            Form d(57, 0);
        } catch (std::exception&e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------     Test01     --------------------" << std::endl;
        std::cout << "basic test: Form throws no exception if grades are within limits\nforms are unsined by default";
        std::cout << std::endl;
        
        try {
            Form a(2, 45);
            Form b(17, 45);
            Form c(12, 45);
            Form d(57, 10);

            std::cout << a << std::endl;
            std::cout << b << std::endl;
            std::cout << c << std::endl;
            std::cout << d << std::endl;
            
        } catch (std::exception&e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------     Test02     --------------------" << std::endl;
        std::cout << "Form throws no exception if every value is in range. form is signed\nif grade of bureaucrat is high enough" << std::endl;
        std::cout << std::endl;
        
        try {
            Form a("Car", 94, 135);
            Form b("Ship", 149, 139);
            Form c("Train", 1, 1);

            std::cout << a << std::endl;
            std::cout << b << std::endl;
            std::cout << c << std::endl;

            Bureaucrat Josep("Josep", 145);
            Bureaucrat Nicol("Nicol", 34);
            Bureaucrat Alja("Alja", 1);
            std::cout << std::endl;
        
            Nicol.signForm(a);
            Alja.signForm(b);
            Josep.signForm(c);
            std::cout << std::endl;
        
            std::cout << a << std::endl;
            std::cout << b << std::endl;
            std::cout << c << std::endl;
            
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
