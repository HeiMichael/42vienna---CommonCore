/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:20:05 by miheider          #+#    #+#             */
/*   Updated: 2024/11/26 11:45:50 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>

class PmergeMe {
    private:
        int         					_struggler_vector;
        std::vector<int>				_input_vector;
        std::vector<std::vector<int> >	_helper_vector;
		std::vector<int>	            _size_vector;
        std::vector<int>                _jacobsthal_vector;

		void							pair_vector();
		void							sort_vector_first();
		void							sort_back_vector();
        void                            create_jacobsthal_vector(int n);
        void                            is_sorted_vector(int argc);
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void    sort_deque(std::vector<int>& input);
};
