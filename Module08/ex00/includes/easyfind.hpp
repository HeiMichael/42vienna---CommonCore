/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:44:27 by miheider          #+#    #+#             */
/*   Updated: 2024/10/14 17:04:54 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <exception>

class NumberNotFoundException : public std::exception {
    public:
        const char * what() const throw();
};

template <typename T>
void easyfind(T& vec, int target);

#include "../srcs/easyfind.tpp"
