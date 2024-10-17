/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:50:24 by miheider          #+#    #+#             */
/*   Updated: 2024/10/15 16:53:48 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array {
    private:
        T*				_elements;
        unsigned int	_n;
    public:
        Array();
        Array(unsigned int n);
        ~Array();
        Array(const Array& other);
        Array& operator=(const Array& other);

        unsigned int	size() const;

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		class IndexOutOfBoundsException : public std::exception {
			public:
				const char * what() const throw();
		};
};

#include "../srcs/Array.tpp"
