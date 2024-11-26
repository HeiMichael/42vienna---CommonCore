/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:45:43 by miheider          #+#    #+#             */
/*   Updated: 2024/11/26 13:40:10 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	comparisons = 0;

//Default constructor
PmergeMe::PmergeMe() {
    //std::cout << "Default constructor (PmergeMe) called" << std::endl;
}

/*Counts the comparisons made by program*/
bool compareWithCounter(const std::vector<int>& a, const std::vector<int>& b) {
    comparisons++; 
    return a < b; 
}

/*prints the std::deque<std::deque<int> > members*/
void	print_vector_matrix(const std::vector<std::vector<int> >& vec) {
	std::cout << "Pairs:" << std::endl;
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << "Pair " << i << ":\t"; 
		for (size_t j = 0; j < vec[i].size(); j++) {
			std::cout << vec[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

/*prints members of std::deque<int>*/
void	print_vector(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

/*checks if the members of the passed deque are correctly sorted or not*/
// void	PmergeMe::is_sorted_deque(int argc) {
// 	int error = 0;
// 	for (size_t i = 1; i < _helper_deque.size(); i++) {
// 		if (_helper_deque[i].size() > 1) {
// 			std::cout << "Too much numbers in deque!!!" << std::endl;
// 			return ;
// 		}
// 		if (_helper_deque[i][0] < _helper_deque[i - 1][0]) {
// 			// std::cout << "Is not sorted!!!!" << std::endl;
// 			error += 1;
// 		}
// 	}
// 	if (error != 0 || _helper_deque.size() != static_cast<size_t>(argc))
// 		std::cout << "NO GOOD SORTING - wrong sorts:\t" << error << std::endl;
// 	else
// 		std::cout << "Perfectly sorted. Thank you!" << std::endl;
// }

/*this functions creates a deque which contains the jacobsthal numbers. first
we create the right amount Jacobsthal numbers and store them in temp. then we 
put those numbers and store them at the right place in _jacobsthal_deque which
was created with -1 at every index. After that we fill in the gaps by a number
which is -1 lower than the number in the previous slot. */
void PmergeMe::create_jacobsthal_vector(int n) {
    std::deque<int> temp;

	_jacobsthal_vector.clear();
    if (n <= 0) return;
    temp.push_back(1);
	if (n == 2) {
		temp.push_back(2);
	}
    if (n > 2) {
        temp.push_back(3);
		for (int i = 2; temp[i - 1] < n; ++i) {
			int next_num = temp[i - 1] + 2 * temp[i - 2];
			temp.push_back(next_num);
		}
    }
    _jacobsthal_vector.resize(n, -1);
	_jacobsthal_vector[0] = 1;
	for (size_t i = 1; i < temp.size(); ++i) {
        int value = temp[i - 1];
        if (value < n) {
			if (temp[i] < static_cast<int>(_helper_vector.size())) {
				_jacobsthal_vector[value] = temp[i];
			} else {
				_jacobsthal_vector[value] = n;
			}
        }
    }
	for (size_t i = 0; i < _jacobsthal_vector.size(); i++) {
		if (_jacobsthal_vector[i] < 0) {
			_jacobsthal_vector[i] = _jacobsthal_vector[i - 1] - 1;
		}
	}
}

/*this function finnaly sorts the numbers back. it splits the deque
and stores all the first halves in the temp deque. then the second
halves are sorted in. if one of the deques is longer, than it should be
it will be split again and sorted in.*/
void PmergeMe::sort_back_vector() {
    std::vector<std::vector<int> > temp;
    std::vector<int> first_half, second_half, protrusion;
    size_t i;
    int counter = 0;

    temp.clear();
    create_jacobsthal_vector(_helper_vector.size());
    for (i = 0; i < _helper_vector.size(); ++i) {
        first_half.clear();
        if (_helper_vector[i].size() == static_cast<size_t>(2 * _size_vector[1])) {
            first_half.assign(_helper_vector[i].begin(), _helper_vector[i].begin() + _size_vector[1]);
            temp.push_back(first_half);
            _helper_vector[i].erase(_helper_vector[i].begin(), _helper_vector[i].begin() + _size_vector[1]);
        } else {
            protrusion.clear();
            protrusion.assign(_helper_vector[i].end() - _size_vector[0], _helper_vector[i].end());
            _helper_vector[i].erase(_helper_vector[i].end() - _size_vector[0], _helper_vector[i].end());
            if (_helper_vector[i].size() == static_cast<size_t>(2 * _size_vector[1])) {
                first_half.assign(_helper_vector[i].begin(), _helper_vector[i].begin() + _size_vector[1]);
                temp.push_back(first_half);
                _helper_vector[i].erase(_helper_vector[i].begin(), _helper_vector[i].begin() + _size_vector[1]);
            }
        }
    }
    second_half.clear();
    second_half.assign(_helper_vector[0].begin(), _helper_vector[0].end());
    temp.insert(temp.begin(), second_half);
    counter++;
    for (i = 1; i < _helper_vector.size(); ++i) {
        second_half.clear();
        size_t jt_idx = _jacobsthal_vector[i] - 1;
        second_half.assign(_helper_vector[jt_idx].begin(), _helper_vector[jt_idx].end());
        std::vector<std::vector<int> >::iterator pos =
            std::lower_bound(temp.begin(), temp.begin() + (jt_idx + counter), second_half, compareWithCounter);
        temp.insert(pos, second_half);
        counter++;
    }
    if (!protrusion.empty()) {
        std::vector<std::vector<int> >::iterator pos =
            std::lower_bound(temp.begin(), temp.end(), protrusion, compareWithCounter);
        temp.insert(pos, protrusion);
    }
    _size_vector.erase(_size_vector.begin());
    _size_vector.erase(_size_vector.begin());
    _helper_vector = temp;
    if (_size_vector[1] >= 1) {
        sort_back_vector();
    }
    if (_struggler_vector >= 0) {
        second_half.clear();
        second_half.push_back(_struggler_vector);
        std::vector<std::vector<int> >::iterator pos =
            std::lower_bound(_helper_vector.begin(), _helper_vector.end(), second_half, compareWithCounter);
        _helper_vector.insert(pos, second_half);
        _struggler_vector = -1;
    }
}

void PmergeMe::sort_vector_first() {
    std::vector<int> temp;
    temp.push_back(-1);

    if (_helper_vector.size() % 2 == 1) {
        temp = _helper_vector.back();
        _size_vector.insert(_size_vector.begin(), temp.size());
        _helper_vector.pop_back();
    }

    for (size_t i = 0; i < _helper_vector.size(); ++i) {
        if (i % 2 == 0) {
            if (_helper_vector[i][0] > _helper_vector[i + 1][0]) {
                if (temp.front() == -1 && i == _helper_vector.size() - 2) {
                    _size_vector.insert(_size_vector.begin(), _helper_vector[i + 1].size());
                }
                _helper_vector[i].insert(_helper_vector[i].end(), _helper_vector[i + 1].begin(), _helper_vector[i + 1].end());
                _helper_vector[i + 1].clear();
                comparisons++;
            } else {
                if (temp.front() == -1 && i == _helper_vector.size() - 2) {
                    _size_vector.insert(_size_vector.begin(), _helper_vector[i].size());
                }
                _helper_vector[i + 1].insert(_helper_vector[i + 1].end(), _helper_vector[i].begin(), _helper_vector[i].end());
                _helper_vector[i].clear();
                comparisons++;
            }
        }
    }

    for (std::vector<std::vector<int> >::iterator it = _helper_vector.begin(); it != _helper_vector.end();) {
        if (it->empty()) {
            it = _helper_vector.erase(it);
        } else {
            ++it;
        }
    }

    if (!temp.empty() && temp[0] > 0) {
        _helper_vector.back().insert(_helper_vector.back().end(), temp.begin(), temp.end());
    }

    if (_helper_vector.size() > 1) {
        _size_vector.insert(_size_vector.begin(), _helper_vector[0].size());
    }

    while (_helper_vector.size() > 1) {
        sort_vector_first();
    }
}

void PmergeMe::pair_vector() {
    if (_input_vector.size() % 2 == 1) {
        _struggler_vector = _input_vector.back();
        _input_vector.erase(_input_vector.end() - 1);
    }
    for (size_t i = 0; i < _input_vector.size() - 1; i++) {
        if (i % 2 == 0) {
            std::vector<int> new_pair;
            if (_input_vector[i] > _input_vector[i + 1]) {
                new_pair.push_back(_input_vector[i]);
                new_pair.push_back(_input_vector[i + 1]);
                comparisons++;
            } else {
                new_pair.push_back(_input_vector[i + 1]);
                new_pair.push_back(_input_vector[i]);
                comparisons++;
            }
            _helper_vector.push_back(new_pair);
        }
    }
    _size_vector.insert(_size_vector.begin(), 1);
    _size_vector.insert(_size_vector.begin(), _helper_vector[0].size());
    _size_vector.push_back(0);
    _size_vector.push_back(0);
}

PmergeMe::PmergeMe(int argc, char** argv) : _struggler_vector(-1) {
    double elapsed_time;
    std::cout << "Before: ";
    for (int i = 0; i < argc - 1; ++i) {
        int value = std::atoi(argv[i]);
        _input_vector.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::clock_t start_vector = std::clock();
    if (argc == 3) {
        if (_input_vector[0] > _input_vector[1])
            std::swap(_input_vector[0], _input_vector[1]);
        comparisons++;
        std::clock_t end_vector = std::clock();
        elapsed_time = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;
        std::cout << "After: ";
        for (size_t i = 0; i <= 1; i++) {
            std::cout << _input_vector[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    if (argc == 4) {
        if (_input_vector[0] > _input_vector[1])
            std::swap(_input_vector[0], _input_vector[1]);
        comparisons++;
        std::clock_t end_vector = std::clock();
        elapsed_time = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;
        std::cout << "After: ";
        for (size_t i = 0; i <= 1; i++) {
            std::cout << _input_vector[i] << " ";
        }
        std::cout << std::endl;
        return;
    }
    _size_vector.insert(_size_vector.begin(), 1);
    pair_vector();
    sort_vector_first();
    sort_back_vector();
    std::clock_t end_vector = std::clock();
    elapsed_time = static_cast<double>(end_vector - start_vector) / CLOCKS_PER_SEC;
    std::cout << "After: ";
    for (size_t i = 0; i < _helper_vector.size(); i++) {
        std::cout << _helper_vector[i][0] << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector: " << elapsed_time << " sec" << std::endl;
}

//Destructor
PmergeMe::~PmergeMe() {
    //std::cout << "Destructor (PmergeMe) called" << std::endl;
}

//Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

//Copy assignment constructor
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other)
        return (*this);
    return *this;
}

    /* // Prints the jacobsthal vector
    std::cout << "jacobsthal_vector: ";
    print_vector(_jacobsthal_vector); */
	
	/* // Prints the member of _helper_vector:
	std::cout << "helper:\t" << std::endl;
	print_vector_matrix(_helper_vector); */

	/* // Prints members of _size_vector, which stores the length of the first vector on each level
	and the last (if odd) or the smaller of the last two (if even)
	std::cout << "print_size_vector:\t";
	print_vector(_size_vector); */

	/* // Prints the size of the _helper_vector
	std::cout << "helper size:\t" << _helper_vector.size() << std::endl; */

	/* // Prints the struggler, if there is one
	std::cout << "Struggler:\t" << _struggler_vector << std::endl; */







