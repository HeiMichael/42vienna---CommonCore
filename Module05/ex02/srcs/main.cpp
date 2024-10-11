/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:19:41 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 13:24:44by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

std::ostream    &operator<<(std::ostream &ostream, Bureaucrat &print);
std::ostream    &operator<<(std::ostream &ostream, AForm &print);
std::ostream    &operator<<(std::ostream &ostream, PresidentialPardonForm &print);
std::ostream    &operator<<(std::ostream &ostream, RobotomyRequestForm &print);
std::ostream    &operator<<(std::ostream &ostream, ShrubberyCreationForm &print);

int main() {
    {
        std::cout << "--------------------     Test00     --------------------" << std::endl;
        std::cout << "three bureaucrats trying to sign (72 required) or execute (45 required)\nthey are successfull depending on their grade" << std::endl;
        std::cout << std::endl;
        
        try {
        AForm* a = new RobotomyRequestForm("Car");
        AForm* b = new RobotomyRequestForm("Train");
        AForm* c = new RobotomyRequestForm("Ship");
        Bureaucrat Jakob("Jakob", 192);
        Bureaucrat Josep("Josep", 52);
        Bureaucrat Franzi("Franzi", 132);
        
        Jakob.signAForm(*a);
        Josep.signAForm(*b);
        Franzi.signAForm(*c);
        a->execute(Jakob);
        b->execute(Josep);
        c->execute(Franzi);
        a->execute(Jakob);
        b->execute(Josep);
        c->execute(Franzi);
        delete a;
        delete b;
        delete c;
        } catch (std::exception&e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------     Test01     --------------------" << std::endl;
        std::cout << "three bureaucrats trying to sign (25 required) or execute (5 required)\nthey are successfull depending on their grade" << std::endl;
        std::cout << std::endl;
        
        try {
        AForm* a = new PresidentialPardonForm("Car");
        AForm* b = new PresidentialPardonForm("Train");
        AForm* c = new PresidentialPardonForm("Ship");
        Bureaucrat Jakob("Jakob", 12);
        Bureaucrat Josep("Josep", 52);
        Bureaucrat Franzi("Franzi", 132);
        
        Jakob.signAForm(*a);
        Josep.signAForm(*b);
        Franzi.signAForm(*c);
        std::cout << *a << std::endl;
        std::cout << *b << std::endl;
        std::cout << *c << std::endl;
        a->execute(Jakob);
        b->execute(Josep);
        c->execute(Franzi);
        a->execute(Jakob);
        b->execute(Josep);
        c->execute(Franzi);
        delete a;
        delete b;
        delete c;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << "--------------------     Test02     --------------------" << std::endl;
        std::cout << "three bureaucrats trying to sign (145 required) or execute (137 required)\nthey are successfull depending on their grade" << std::endl;
        std::cout << std::endl;
        
        try {
            AForm* a = new ShrubberyCreationForm("Car");
            AForm* b = new ShrubberyCreationForm("Train");
            AForm* c = new ShrubberyCreationForm("Ship");
            Bureaucrat Jakob("Jakob", 12);
            Bureaucrat Josep("Josep", 52);
            Bureaucrat Franzi("Franzi", 148);
        
            Jakob.signAForm(*a);
            Josep.signAForm(*b);
            Franzi.signAForm(*c);
            a->execute(Jakob);
            b->execute(Josep);
            c->execute(Franzi);
            a->execute(Jakob);
            b->execute(Josep);
            c->execute(Franzi);
        delete a;
        delete b;
        delete c;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        } 
    }
    {
        std::cout << "--------------------     Test03     --------------------" << std::endl;
        std::cout << "three bureaucrats trying to sign (25 required) or execute (5 required)\nthey are successfull depending on their grade" << std::endl;
        std::cout << std::endl;
        
        try {
            AForm* a = new PresidentialPardonForm("Car");
            AForm* b = new PresidentialPardonForm("Train");
            AForm* c = new PresidentialPardonForm("Ship");
            Bureaucrat Jakob("Jakob", 12);
            Bureaucrat Josep("Josep", 52);
            Bureaucrat Franzi("Franzi", 132);
        
            Jakob.signAForm(*a);
            Josep.signAForm(*b);
            Franzi.signAForm(*c);
            a->execute(Jakob);
            b->execute(Josep);
            c->execute(Franzi);
            a->execute(Jakob);
            b->execute(Josep);
            c->execute(Franzi);
        delete a;
        delete b;
        delete c;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
