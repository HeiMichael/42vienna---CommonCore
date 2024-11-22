/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:20:05 by miheider          #+#    #+#             */
/*   Updated: 2024/11/21 19:19:20 by miheider         ###   ########.fr       */
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

class PmergeMe {
    private:
        int         					_struggler_deque;
        int                             _size_input;
        std::deque<int>					_input_deque;
        std::deque<std::deque<int> >	_helper_deque;
		std::deque<int>		            _size_deque;
        std::deque<int>                 _jacobsthal_deque;
        bool                            _three;

		void							pair_deque();
		void							sort_deque_first();
		void							sort_back_deque();
        void                            create_jacobsthal_deque(int n);
        void                            is_sorted_deque(int argc);
    public:
        PmergeMe();
        PmergeMe(int argc, char **argv);
        ~PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);

        void    sort_deque(std::deque<int>& input);
};
