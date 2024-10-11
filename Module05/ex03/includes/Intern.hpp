/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:26:25 by miheider          #+#    #+#             */
/*   Updated: 2024/10/03 11:35:44 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <string>

class Intern {
    private:

    public:
        Intern();
        ~Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        AForm*  makeForm(const std::string name_form, const std::string target_form);

        //nested exception classes
        class InvalidFile : public std::exception {
            public:
                const char* what() const throw();
        };
};
