/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 08:19:18 by miheider          #+#    #+#             */
/*   Updated: 2024/10/09 10:06:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string   _name;
        int  				_grade;
    public:
        //Orthodox Canonical AForm
        Bureaucrat();
        Bureaucrat(const std::string name);
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        //member function
        std::string getName() const;
        int			getGrade() const;
        void        signForm(Form& test);
        void        incrementGrade();
        void        decrementGrade();

        //nested exception classes
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};


