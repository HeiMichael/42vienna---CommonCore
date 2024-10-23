/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:59:19 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 11:06:48miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _size(0) {
	std::cout << "Default constructor (Span) called." << std::endl;
}

Span::Span(unsigned int N): _size(N) {
	std::cout << "Constructor (Span, unsigned int) called" << std::endl;
}

Span::~Span() {
	std::cout << "Destructor (Span) called" << std::endl;
}

Span::Span(const Span& other) {
	*this = other;
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_size = other._size;
		_vector = other._vector;
	}
	return *this;
}

void			Span::addNumber(int num) {
	if (_vector.size() == _size)
		throw Span::CanNotAddANumberException();
	_vector.push_back(num);
}

unsigned int	Span::shortestSpan() const {
	if (_vector.empty())
		throw Span::VectorIsEmptyException();
	if (_vector.size() == 1)
		throw Span::TooFewNumbersInVectorException();
	
	std::vector<int> sortedVector = _vector;
	std::sort(sortedVector.begin(), sortedVector.end());
	
	unsigned int shortest = UINT_MAX;
	std::vector<int>::iterator iter = sortedVector.begin();
	while (iter != sortedVector.end() - 1) {
		unsigned int diff = *(iter + 1) - *iter;
		if (diff < shortest)
			shortest = diff;
		iter++;
	}
	return shortest;
}

unsigned int	Span::longestSpan() const {
	unsigned int longest = 0;
	
	if (_vector.empty()) {
		throw Span::VectorIsEmptyException();
	} else {
		if (_vector.size() == 1) {
			throw Span::TooFewNumbersInVectorException();
		} else {
			std::vector<int> sortedVector = _vector;
			std::sort(sortedVector.begin(), sortedVector.end());
			longest = sortedVector.back() - sortedVector.front();
		}
	}
	return longest;
}

unsigned int	Span::get_size() const {
	return _size;
}

void			Span::fill(unsigned int n) {
	int* numbers;
    try {
        numbers = new int[n];
    } catch (const std::bad_alloc& e) {
        throw Span::MemoryAllocationException();  // Custom exception for memory allocation failure
    }

	srand(time(NULL));
    for (unsigned int i = 0; i < n; i++)
    {
        const int value = rand();
        numbers[i] = value;
		addNumber(static_cast<int>(numbers[i]));
    }
	delete [] numbers;
}

void			Span::fill(unsigned int n, unsigned int range) {
	//std::cout << "capacity:\t" << _vector.capacity() << "\nsize:\t\t" << _size << "\nn:\t\t" << n << std::endl;
	if (n > 1000000000)
		throw Span::TooManyNumbersAttemptException();
	if (range > std::numeric_limits<unsigned int>::max())
        throw Span::RangeOverflowException();
	if ((_size - _vector.size()) < n)
		throw RangeTooHighException();
	
	int* numbers;
    try {
        numbers = new int[n];
    } catch (const std::bad_alloc& e) {
        throw Span::MemoryAllocationException();  // Custom exception for memory allocation failure
    }

	srand(time(NULL));
    for (unsigned int i = 0; i < n; i++)
    {
        const int value = rand() % range;
        numbers[i] = value;
		addNumber(static_cast<int>(numbers[i]));
		//std::cout << "number added:\t" << numbers[i] << std::endl;
    }
	delete [] numbers;
}

const char * Span::RangeTooHighException::what() const throw() {
	return "The Range is greater than spots left in the vector";
}

const char * Span::CanNotAddANumberException::what() const throw() {
	return "No more numbers can be stored.";
}

const char * Span::TooFewNumbersInVectorException::what() const throw() {
	return "There are too few numbers stored in the vector";
}

const char * Span::VectorIsEmptyException::what() const throw() {
	return "The vector is empty";
}

const char * Span::TooManyNumbersAttemptException::what() const throw() {
	return "You are trying to create too much numbers";
}

const char * Span::RangeOverflowException::what() const throw() {
	return "The Range is too high (overflow)";
}

const char * Span::MemoryAllocationException::what() const throw() {
	return "Memory Allocation failed";
}

