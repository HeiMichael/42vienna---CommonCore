/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:51:38 by miheider          #+#    #+#             */
/*   Updated: 2024/10/18 11:12:39 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include<stack>
#include<iostream>

/* we inherit from std::stack<T> so we have access to its member functions which
are:	- (constructor)	Construct stack
		- empty			Test whether container is empty
		- size			Return size
		- top			Access next element
		- push			Insert element
		- emplace		Construct and insert element
		- pop			Remove top element
		- swap			Swap contents

Non-member function overloads
		- relational operators	(==, !=, <, <=, >, >=)
		- swap (stack)	Exchange contents of stacks (public member function)

Non-member class specializations
		- uses_allocator<stack> */

template <typename T>
class MutantStack : public std::stack<T> {
    private:

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack& operator=(const MutantStack &other);
		
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "../srcs/MutantStack.tpp"
