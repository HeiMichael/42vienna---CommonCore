/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:13:24 by miheider          #+#    #+#             */
/*   Updated: 2024/10/12 12:48:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Data {
    private:

    public:
        std::string _test;

        Data();
        ~Data();
        Data(const Data& other);
        Data& operator=(const Data& other);
};
