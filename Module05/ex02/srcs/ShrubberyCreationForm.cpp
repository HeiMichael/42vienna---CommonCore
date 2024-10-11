/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 09:36:25 by miheider          #+#    #+#             */
/*   Updated: 2024/10/11 14:43:15 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

std::ostream    &operator<<(std::ostream &ostream, ShrubberyCreationForm &print) {
    std::cout << "Form: " << print.getName() << "\ngrade_required: " << print.getGradeRequired() << "\ngrade to execute: " << print.getGradeToExecute() << std::endl;
    return ostream;
}

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("noname_SCF") {
	std::cout << "Default constrctor (ShrubberyCreationForm) called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Constructor (ShrubberyCreationForm) for " << _target << " called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Destructor (ShrubberyCreationForm) called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm("ShrubbyCreationForm", 145, 137), _target(getTarget()) {
	std::cout << "Copy constructor (ShrubbyCreationForm) called to copy " << getName() << std::endl;
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "Copy assignment operator (ShrubberyCreationForm) called" << std::endl;
    if (this == &other) { 
        return *this;
    }
    return *this;
}

void					ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    try {
        if (getSigned() == false) {
            throw AForm::FormNotSignedException();
        }
        else if (executor.getGrade() > getGradeToExecute())
            throw Bureaucrat::GradeTooLowException();
        else {
            std::cout << executor.getName() << " created file" << std::endl;
            std::ofstream file (this->getTarget().append("_shrubbery").c_str());
            file << "                                                         . " << std::endl;
            file << "                                              .         ; " << std::endl;  
            file << "                 .              .              ;%     ;; " << std::endl;
            file << "                   ,           ,                :;%  %; " << std::endl;
            file << "                    :         ;                   :;%;'     ., " << std::endl;
            file << "           ,.        %;     %;            ;        %;'    ,; " << std::endl;
            file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%' " << std::endl;
            file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
            file << "               ;%;      %;        ;%;        % ;%;  ,%;' " << std::endl;
            file << "                `%;.     ;%;     %;'         `;%%;.%;' " << std::endl;
            file << "                 `:;%.    ;%%. %@;        %; ;@%;%' " << std::endl;
            file << "                    `:%;.  :;bd%;          %;@%;' " << std::endl;
            file << "                      `@%:.  :;%.         ;@@%;' " << std::endl;
            file << "                        `@%.  `;@%.      ;@@%; " << std::endl;
            file << "                          `@%%. `@%%    ;@@%; " << std::endl;
            file << "                            ;@%. :@%%  %@@%; " << std::endl;
            file << "                              %@bd%%%bd%%:; " << std::endl;
            file << "                                #@%%%%%:;; " << std::endl;
            file << "                                %@@%%%::; " << std::endl;
            file << "                                %@@@%(o);  . ' " << std::endl;
            file << "                                %@@@o%;:(.,' " << std::endl;
            file << "                            `.. %@@@o%::; " << std::endl;
            file << "                               `)@@@o%::; " << std::endl;
            file << "                                %@@(o)::; " << std::endl;
            file << "                               .%@@@@%::; " << std::endl;
            file << "                               ;%@@@@%::;. " << std::endl;
            file << "                              ;%@@@@%%:;;;. " << std::endl;
            file << "                          ...;%@@@@@%%:;;;;,.. " << std::endl;
            file.close();
        }
    } catch (AForm::FormNotSignedException& e) {
        std::cout << e.what() << std::endl;
        return ;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
        return ;
    }
}

std::string				ShrubberyCreationForm::getTarget(void) const {
    return _target;
}
