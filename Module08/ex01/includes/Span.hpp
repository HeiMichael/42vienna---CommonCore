/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:47:18 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 11:48:04 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits>

class Span {
	private:
		std::vector<int>	_vector;
		unsigned int		_size;
    public:
		Span();
		Span(unsigned int N);
		~Span();
		Span(const Span& other);
		Span& operator=(const Span& other);

		void			addNumber(int num);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		unsigned int	get_size() const;
		void			fill(unsigned int n);
		void			fill(unsigned int n, unsigned int range);

		class CanNotAddANumberException : std::exception {
			public:
				const char * what() const throw();
		};
		class TooFewNumbersInVectorException : std::exception {
			public:
				const char * what() const throw();
		};
		class VectorIsEmptyException : std::exception {
			public:
				const char * what() const throw();
		};
		class RangeTooHighException : std::exception {
			public:
				const char * what() const throw();
		};
		class TooManyNumbersAttemptException : std::exception {
			public:
				const char * what() const throw();
		};
		class RangeOverflowException : std::exception {
			public:
				const char * what() const throw();
		};
		class MemoryAllocationException : std::exception {
			public:
				const char * what() const throw();
		};
};
