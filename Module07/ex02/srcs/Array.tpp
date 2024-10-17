/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:35:47 by miheider          #+#    #+#             */
/*   Updated: 2024/10/16 09:25:43 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Array.hpp"

template <typename T>
Array<T>::Array(): _n(0) {
	std::cout << "Default Constructor (Array) called." << std::endl;
	_elements = new T[_n];
}

template <typename T>
Array<T>::Array(unsigned int n): _n(n) {
	std::cout << "Unsigned int constructor (Array) called." << std::endl;
	_elements = new T[_n];
}

template <typename T>
Array<T>::~Array() {
    if (_elements) {
        delete[] _elements;
    }
}

template <typename T>
Array<T>::Array(const Array& other): _n(other._n) {
	std::cout << "Copy Constructor (Array) called." << std::endl;
	_elements = new T[_n];
	for (unsigned int i = 0; i < _n; i++) {
		_elements[i] = other._elements[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	std::cout << "Copy assignment operator called." << std::endl;
	if (this != &other) {
		delete [] _elements;  // Free current memory
		_n = other._n;
		_elements = new T[_n];  // Allocate new memory
		for (unsigned int i = 0; i < _n; i++) {
			_elements[i] = other._elements[i];  // Copy each element
		}
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const {
    return _n;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _n || index < 0) {
        throw IndexOutOfBoundsException();
    }
    return _elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _n || index < 0) {
        throw IndexOutOfBoundsException();
    }
    return _elements[index];
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
	return "Index out-of-bounds";
}
