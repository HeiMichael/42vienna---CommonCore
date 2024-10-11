/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:44 by miheider          #+#    #+#             */
/*   Updated: 2024/10/03 11:43:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Default constructor (Intern) called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Destructor (Intern) called" << std::endl;
}

Intern::Intern(const Intern& other) {
    std::cout << "Copy constructor (Intern) called" << std::endl;
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    std::cout << "Copy assignment operator (Intern) called" << std::endl;
    if (this == &other)
        return *this;
    return *this;
}

AForm* createPresidentalPardon(const std::string target_form) {
    return new PresidentialPardonForm(target_form);
}

AForm* createRobotomyRequest(const std::string target_form) {
    return new RobotomyRequestForm(target_form);
}

AForm* createShrubberyCreation(const std::string target_form) {
    return new ShrubberyCreationForm(target_form);
}

AForm* Intern::makeForm(const std::string name_form, const std::string target_form) {
    AForm *(*forms[])(const std::string target_form) = {&createPresidentalPardon, &createRobotomyRequest, &createShrubberyCreation};
    std::string name[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    
    int number_of_forms = sizeof(name) / sizeof(name[0]);
    try {
        for (int i = 0; i < number_of_forms; i++) {
            if (name_form == name[i]) {
                std::cout << "Intern creates " << name_form << std::endl;
                return (forms[i](target_form));
            }
        }
        throw InvalidFile();
    }
    catch (Intern::InvalidFile& e) {
        std::cout << "'" << name_form << "'" << " couldn't be created because " << e.what() << std::endl;
    }
    return NULL;
}

const char* Intern::InvalidFile::what() const throw() {
    return "form doesn't exist (Intern)";
}
