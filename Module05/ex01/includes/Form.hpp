/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:51:07 by miheider          #+#    #+#             */
/*   Updated: 2024/09/30 14:06:33 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string 	_name;
        bool             	_signed;
        const int       	_grade_required;
        const int			_grade_to_execute;
    public:
        Form();
        Form(int grade_required, int grade_to_execute);
        Form(std::string name, int grade_required, int grade_to_execute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        //member functions
        std::string	getName() const;
        bool        getSigned() const;
        int			getGradeRequired() const;
        int 		getGradeToExecute() const;
        void  	 	beSigned(Bureaucrat& change_status);

        //nested classes
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
};
