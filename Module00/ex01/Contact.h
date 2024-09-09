/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 15:32:14 by miheider          #+#    #+#             */
/*   Updated: 2024/08/16 16:54:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include<iostream>
# include<string>

class Contact {
    private:
    std::string _index;
    std::string _lastname;
    std::string _firstname;
    std::string _nickname;
    std::string _number;
    std::string _secret; 
    
	public:
    void		set_lastname(std::string lastname);
    void		set_firstname(std::string firstname);
    void		set_nickname(std::string nickname);
    void		set_number(std::string number);
    void		set_secret(std::string secret);
    void        set_index(int index);
    std::string	get_lastname() const;   
    std::string	get_firstname() const;   
    std::string	get_nickname() const;   
    std::string	get_number() const;   
    std::string	get_secret() const;
    std::string get_index() const; 
};

#endif
