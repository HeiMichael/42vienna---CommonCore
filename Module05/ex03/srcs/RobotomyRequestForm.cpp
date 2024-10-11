/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:30:01 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 14:47:12 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

std::ostream    &operator<<(std::ostream &ostream, RobotomyRequestForm &print) {
    std::cout << "Form: " << print.getName() << "\ngrade_required: " << print.getGradeRequired() << "\ngrade to execute: " << print.getGradeToExecute() << std::endl;
    return ostream;
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("noname_RRF") {
	std::cout << "Default constrctor (RobotomyRequestForm) called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Constructor (RobotomyRequestForm) for " << _target << " called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Destructor (RobotomyRequestForm) called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm("RobotomyRequestFormForm", 72, 45), _target(getTarget()) {
	std::cout << "Copy constructor (RobotomyRequestForm) called to copy " << getName() << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "Copy assignment operator (RobotomyRequestForm) called" << std::endl;
	if (this != &other)
		return *this;
	return *this;
}

void					RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    static int i;

    try {
        if (getSigned() == false) {
            throw AForm::FormNotSignedException();
        }
        if (executor.getGrade() > getGradeToExecute())
            throw Bureaucrat::GradeTooLowException();
        else {
            if (i % 2 == 0) {
                std::cout << getTarget() << " has been robotomized successfully" << std::endl;
            } else {
                std::cout << getTarget() << "'s robotomization failed" << std::endl;
            }
        }
    } catch (AForm::FormNotSignedException& e) {
        std::cout << e.what() << std::endl;
        return ;
    } catch (Bureaucrat::GradeTooLowException& e) {
            std::cout << e.what() << std::endl;
            return ;
    }
    i++;
}

std::string				RobotomyRequestForm::getTarget(void) const {
    return _target;
}
