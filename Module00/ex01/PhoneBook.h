/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:34:08 by miheider          #+#    #+#             */
/*   Updated: 2024/08/29 17:34:53 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.h"
# include <iomanip>

class PhoneBook {
    private:
        Contact		_contacts[8];

        std::string	_format_input(std::string text) const;
        bool        _is_ascii_value(std::string input) const;
        bool        _process_entries(std::string entry, std::string *saving);
    
    public:
        void		add(void);
        void		search(void);
};

#endif
