/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:20:10 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 16:53:45 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
#define HARL_H
#include <string>
#include <iostream>

class Harl {

    private:
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void );
        
    public:
        Harl();
        ~Harl();
        void complain( std::string level );
};

#endif

