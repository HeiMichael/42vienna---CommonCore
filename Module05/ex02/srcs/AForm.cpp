/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:44:59 by miheider          #+#    #+#             */
/*   Updated: 2024/09/30 14:22:548 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

std::ostream    &operator<<(std::ostream &ostream, AForm &print) {
    std::cout << print.getName() << "\nis signed: " << print.getSigned() << "\ngrade required: " << print.getGradeRequired() << "\ngrade_to_execute: " << print.getGradeToExecute() << std::endl;
    return ostream;
}

AForm::AForm(): _name("noname"), _signed(false), _grade_required(150), _grade_to_execute(150) {
    std::cout << "Default constructor (AForm) called." << std::endl;
}

AForm::AForm(int grade_required, int grade_to_execute) : _name("default"), _signed(false), _grade_required(grade_required), _grade_to_execute(grade_to_execute) {
    std::cout << "Constructor (AForm int, int) called" << std::endl;
    try {
        if (_grade_required < 1) {
            throw GradeTooHighException();
        }
        if (grade_required > 150) {
            throw GradeTooLowException();
        }
        if (grade_to_execute < 1) {
            throw GradeTooHighException();
        }
        if (grade_to_execute > 150) {
            throw GradeTooLowException();
        }
    }
    catch (const GradeTooHighException) {
        throw;
    }
    catch (const GradeTooLowException) {
        throw;
    } 
}

AForm::AForm(std::string name, int grade_required, int grade_to_execute) : _name(name), _signed(false), _grade_required(grade_required), _grade_to_execute(grade_to_execute) {
    std::cout << "Constructor (Form std::string int, int) called" << std::endl;
    try {
        if (_grade_required < 1) {
            throw GradeTooHighException();
        }
        if (grade_required > 150) {
            throw GradeTooLowException();
        }
        if (grade_to_execute < 1) {
            throw GradeTooHighException();
        }
        if (grade_to_execute > 150) {
            throw GradeTooLowException();
        }
    }
    catch (const GradeTooHighException) {
        throw;
    }
    catch (const GradeTooLowException) {
        throw;
    }
}


AForm::~AForm() {
    std::cout << "Destructor (AForm) called." << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.getName()), _signed(other.getSigned()), _grade_required(other.getGradeRequired()), _grade_to_execute(other.getGradeToExecute()) {
    *this = other;
}

AForm& AForm::operator=(const AForm& other)  {
    if (this != &other)
        return *this;
    return *this;
}

//member function
std::string       AForm::getName() const {
    return _name;
}

bool                    AForm::getSigned() const {
    return _signed;
}

int          AForm::getGradeRequired() const {
    return _grade_required;
}

int          AForm::getGradeToExecute() const {
    return _grade_to_execute;
}

void                    AForm::beSigned(Bureaucrat& b_crat) {
    if (b_crat.getGrade() <= this->getGradeRequired())
        _signed = true;
    else
        throw GradeTooLowException();
}

//nested class exception
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high (AForm)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low (AForm)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed (AForm)";
}
