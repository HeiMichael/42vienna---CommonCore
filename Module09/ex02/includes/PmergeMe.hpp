/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:20:05 by miheider          #+#    #+#             */
/*   Updated: 2024/12/02 12:01:03 by miheider         ###   ########.fr       */
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
        int         					_struggler_deque;
        std::deque<int>					_input_deque;
        std::deque<std::deque<int> >	_helper_deque;
		std::deque<int>	                _size_deque;
        std::deque<int>                 _jacobsthal_deque;
        
        int         					_struggler_vector;
        std::vector<int>				_input_vector;
        std::vector<std::vector<int> >	_helper_vector;
		std::vector<int>	            _size_vector;
        std::vector<int>                _jacobsthal_vector;

        int                             _input;

		void							pair_deque();
		void							sort_deque_first();
		void							sort_back_deque();
        void                            create_jacobsthal_deque(int n);
        void                            is_sorted_deque(int argc);
		
        void							pair_vector();
		void							sort_vector_first();
		void							sort_back_vector();
        void                            create_jacobsthal_vector(int n);
        void                            is_sorted_vector(int argc);
        void                            sort_back_vector_helper();


        
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void    sort_deque(std::deque<int>& input);
};
