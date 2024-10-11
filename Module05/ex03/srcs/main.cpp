/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:19:41 by miheider          #+#    #+#             */
/*   Updated: 2024/10/03 11:19:52by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
        std::cout << "subject test (Robotomy Request)" << std::endl;
        std::cout << std::endl;

        try {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test01     --------------------" << std::endl;
        std::cout << "subject test (Presidential Pardon Form)" << std::endl;
        std::cout << std::endl;
        
        try {
            Intern Jakob;
            AForm* ppf;
            ppf = Jakob.makeForm("presidential pardon", "Bender");
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test02     --------------------" << std::endl;
        std::cout << "subject test (Shrubbery Creation Form)" << std::endl;
        std::cout << std::endl;
        
        try {
            Intern Jakob;
            AForm* scf;
            scf = Jakob.makeForm("shrubbery creation", "Bender");
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test03     --------------------" << std::endl;
        std::cout << "subject test (not existing Form)" << std::endl;
        std::cout << std::endl;
        
        try {        
            Intern Jakob;
            AForm* ne;
            ne = Jakob.makeForm("not existing", "Bender");
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "--------------------     Test04     --------------------" << std::endl;
        std::cout << "a little playthrough" << std::endl;
        std::cout << std::endl;

        try {
		    Bureaucrat *a = new Bureaucrat("President", 1);
		    Intern *z = new Intern();
		    AForm *b = z->makeForm("robotomy request", "Rapid");
		    AForm *c = z->makeForm("shrubbery creation", "Wien");
            std::cout << std::endl;

		    std::cout << *a << std::endl;
		    std::cout << *b << std::endl;
		    std::cout << *c << std::endl;
            std::cout << std::endl;
		
            a->signAForm(*b);
            a->signAForm(*c);
		
            std::cout << std::endl;
		    std::cout << *b << std::endl;
		    std::cout << *c << std::endl;;
            std::cout << std::endl;

            for (int i= 0; i < 10; i++)
                b->execute(*a);
            a->executeForm(*c);
		std::cout << std::endl;

		delete a;
		delete b;
		delete c;
		delete z;
		std::cout << std::endl;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
