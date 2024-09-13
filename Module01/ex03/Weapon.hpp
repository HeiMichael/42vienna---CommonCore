/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 15:45:42 by miheider          #+#    #+#             */
/*   Updated: 2024/09/03 17:12:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include<string>

class Weapon {

    private:
        std::string  _type;

    public:
        Weapon(std::string weapon);
        ~Weapon();
        std::string getType() const;
        void        setType(std::string another_weapon);
};

#endif
