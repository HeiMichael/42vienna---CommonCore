/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:18:36 by miheider          #+#    #+#             */
/*   Updated: 2024/10/09 14:09:45 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

std::ostream    &operator<<(std::ostream &ostream, Bureaucrat &print) {
    std::cout << print.getName() << " bureaucrat grade " << print.getGrade() << "." << std::endl;
    return ostream;
}

Bureaucrat::Bureaucrat(): _name("noname"), _grade(150) {
    std::cout << "Default constructor (Bureaucrat) called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name) {
    _grade = 150;
    std::cout << "Constructor (std::string) for " << _name << "with grade: " << _grade << " called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    if (grade < 1) {
        throw GradeTooHighException();
    } else if (grade > 150) {
        throw GradeTooLowException();
    } else {
        this->_grade = grade;
    }
    std::cout << "Constructor (std::string, int) for " << _name << " with grade: " << _grade << " called." <<std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor (Bureaucrat) called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName()), _grade(other.getGrade()) {
    std::cout << "Copy constructor (Bureaucrat) called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Copy assignment operator (Bureaucrat) called" << std::endl;
    if (this != &other) {               //name is const --> we cannot assign it.
        _grade = other.getGrade();
    }
    return *this;
}

std::string     Bureaucrat::getName() const {
    return _name;
}

int  Bureaucrat::getGrade() const {
    return _grade;
}

void            Bureaucrat::signForm(Form& test) {
    if (test.getSigned() == true) {
        std::cout << "Form already signed" << std::endl;
        return ;
        }
    try {
        test.beSigned(*this);
        std::cout << this->getName() << " signed " << test.getName() << std::endl; 
        } catch (std::exception& e) {
            std::cout << getName() << " could not sign " << test.getName() << " because " << e.what() << std::endl; 
    }
}

void  Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1) {
        throw GradeTooHighException();
    } else {
        _grade -= 1;
    }
}

void  Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150) {
        throw GradeTooLowException();
    } else {
        _grade += 1;
    }
    std::cerr << "value too low. impossible to decrement" << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high (Bureaucrat)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low (Bureaucrat)";
}
