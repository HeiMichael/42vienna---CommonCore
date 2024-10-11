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

class AForm {
    private:
        const std::string	_name;
        bool              	_signed;
        const int    		_grade_required;
        const int    		_grade_to_execute;
    public:
        AForm();
        AForm(int grade_required, int grade_to_execute);
        AForm(std::string name, int grade_required, int grade_to_execute);
        virtual ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        //member functions
        std::string		getName() const;
        bool        	getSigned() const;
        int         	getGradeRequired() const;
        int         	getGradeToExecute() const;
        void        	beSigned(Bureaucrat& change_status);
        virtual void	execute(Bureaucrat const & executor) const = 0;

        //nested classes
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
};
