/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:51:44 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 12:51:16 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
MutantStack<T>::MutantStack(): std::stack<T>() {
    std::cout << "Default constructor (MutantStack) called" << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    std::cout << "Destructor (MutantStack) called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>(other) {
    std::cout << "Copy constructor (MutantStack) called" << std::endl;
    *this = other;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other) {
    std::cout << "Copy assignment operator (MutantStack) called" << std::endl;
    if (this != &other)
        return *this;
    return *this;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();             //we access underlying container's iterator
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::begin() const {
    return this->c.begin();
}

template <typename T>
typename std::deque<T>::const_iterator MutantStack<T>::end() const {
    return this->c.end();
}
