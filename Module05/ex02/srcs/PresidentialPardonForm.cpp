/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 08:44:43 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 14:43:30 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

std::ostream    &operator<<(std::ostream &ostream, PresidentialPardonForm &print) {
    std::cout << "Form: " << print.getName() << "\ngrade_required: " << print.getGradeRequired() << "\ngrade to execute: " << print.getGradeToExecute() << std::endl;
    return ostream;
}

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("noname_PPF") {
	std::cout << "Default constrctor (PresidentalPardonForm) called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "Constructor (PresidentialPardonForm) for " << _target << " called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Destructor (PresidentialPardonForm) called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm("PresidentialPardonForm", 25, 5), _target(getTarget()) {
	std::cout << "Copy constructor (PresidentalPardonForm) called to copy " << getName() << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignment operator (PresidentPardonForm) called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

void					PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		if (getSigned() == false) {
			throw AForm::FormNotSignedException();
		}
		if (executor.getGrade() > getGradeToExecute()) {
			throw Bureaucrat::GradeTooLowException();
		} else {
			std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;	
		}
	} catch (AForm::FormNotSignedException& e) {
        std::cout << e.what() << std::endl;
        return ;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
        return ;
    }
}

std::string				PresidentialPardonForm::getTarget(void) const {
    return _target;
}
