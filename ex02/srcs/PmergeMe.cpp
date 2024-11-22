/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:45:43 by miheider          #+#    #+#             */
/*   Updated: 2024/11/22 22:07:21 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t	comparisons = 0;

//Default constructor
PmergeMe::PmergeMe() {
    //std::cout << "Default constructor (PmergeMe) called" << std::endl;
}

bool compareWithCounter(const std::deque<int>& a, const std::deque<int>& b) {
    comparisons++; 
    return a < b; 
}

void	print_deque_matrix(const std::deque<std::deque<int> >& deq) {
	std::cout << "Pairs:" << std::endl;
	for (size_t i = 0; i < deq.size(); i++) {
		std::cout << "Pair " << i << ":\t"; 
		for (size_t j = 0; j < deq[i].size(); j++) {
			std::cout << deq[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	print_deque(const std::deque<int>& deq) {
    for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void	PmergeMe::is_sorted_deque(int argc) {
	int error = 0;
	for (size_t i = 1; i < _helper_deque.size(); i++) {
		if (_helper_deque[i].size() > 1) {
			std::cout << "Too much numbers in deque!!!" << std::endl;
			return ;
		}
		if (_helper_deque[i][0] < _helper_deque[i - 1][0]) {
			// std::cout << "Is not sorted!!!!" << std::endl;
			error += 1;
		}
	}
	if (error != 0 || _helper_deque.size() != static_cast<size_t>(argc))
		std::cout << "NO GOOD SORTING - wrong sorts:\t" << error << std::endl;
	else
		std::cout << "Perfectly sorted. Thank you!" << std::endl;
}

/*this functions creates a deque which contains the jacobsthal numbers. first
we create the right amount Jacobsthal numbers and store them in temp. then we 
put those numbers and store them at the right place in _jacobsthal_deque which
was created with -1 at every index. After that we fill in the gaps by a number
which is -1 lower than the number in the previous slot. */
void PmergeMe::create_jacobsthal_deque(int n) {
    std::deque<int> temp;

	//temp.clear();
	_jacobsthal_deque.clear();
    if (n <= 0) return;
    temp.push_back(1);
	if (n == 2) {
		temp.push_back(2);
		// return;
	}
    if (n > 2) {
        temp.push_back(3);
		for (int i = 2; temp[i - 1] < n; ++i) {
			int next_num = temp[i - 1] + 2 * temp[i - 2];
			temp.push_back(next_num);
		}
    }
    _jacobsthal_deque.resize(n, -1);
	_jacobsthal_deque[0] = 1;
	for (size_t i = 1; i < temp.size(); ++i) {
        int value = temp[i - 1];
        if (value < n) {
			if (temp[i] < static_cast<int>(_helper_deque.size())) {
				_jacobsthal_deque[value] = temp[i];
			} else {
				_jacobsthal_deque[value] = n;
			}
        }
    }
	for (size_t i = 0; i < _jacobsthal_deque.size(); i++) {
		if (_jacobsthal_deque[i] < 0) {
			_jacobsthal_deque[i] = _jacobsthal_deque[i - 1] - 1;
		}
	}
    // Print the resulting deque
    std::cout << "jacobsthal_deque: ";
    print_deque(_jacobsthal_deque);
    // std::cout << "temp: ";
    // print_deque(temp);
}

/*this function finnaly sorts the numbers back. it splits the deque
and stores all the first halves in the temp deque. then the second
halves are sorted in. if one of the deques is longer, than it should be
it will be split again and sorted in.*/
void PmergeMe::sort_back_deque() {
    std::deque<std::deque<int> > temp;
    std::deque<int> first_half, second_half;
	size_t i = -1;
	int special = -1;

    temp.clear();
	std::cout << "-----------------------" << std::endl;
	create_jacobsthal_deque(_helper_deque.size());
	// std::cout << "helper size:\t" << _helper_deque.size() << std::endl;
	// std::cout << "jt_deque" << std::endl;
	// print_deque(_jacobsthal_deque);
	// print_deque(_size_deque);
	std::cout << "length:\t";
	print_deque(_length);
	std::cout << "helper:\t" << std::endl;
	print_deque_matrix(_helper_deque);
    for (i = 0; i < _helper_deque.size(); i++) {
        first_half.clear();
		if (_helper_deque[i].size() == static_cast<size_t>(2 * _size_deque[0])) {
			first_half.insert(first_half.end(), _helper_deque[i].begin(), _helper_deque[i].begin() + _size_deque[0]);
			temp.push_back(first_half);
			_helper_deque[i].erase(_helper_deque[i].begin(), _helper_deque[i].begin() + _size_deque[0]);
		} else {
			first_half.insert(first_half.end(), _helper_deque[i].begin(), _helper_deque[i].end() - (_length[0]));
			temp.push_back(first_half);
			_helper_deque[i].erase(_helper_deque[i].begin(), _helper_deque[i].end() - (_length[0]));
			special = i;
		}
    }
	i = 0;
	if (i != static_cast<size_t>(special)) {
		second_half.clear();
		second_half.insert(second_half.end(), _helper_deque[0].begin(), _helper_deque[0].end());
		temp.push_front(second_half);
	} else {
		second_half.insert(second_half.end(), _helper_deque[0].begin(), _helper_deque[0].end());
		std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.end(), second_half , compareWithCounter);
		temp.insert(pos, second_half);
	}
	int counter = 1;
    for (i = 1; i < _helper_deque.size(); i++) {
		second_half.clear();
		size_t jt_idx = (_jacobsthal_deque[i]) - 1;
		// std::cout << "jt_index:\t" << jt_idx << std::endl;
		// if (jt_idx > static_cast<size_t>(_helper_deque.size()))
		// 	continue ;
		if (static_cast<int>(jt_idx) == special) {
			second_half.insert(second_half.end(), _helper_deque[jt_idx].begin(), _helper_deque[jt_idx].end());
			std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.end(), second_half , compareWithCounter);
			temp.insert(pos, second_half);			
		} else {
			second_half.insert(second_half.end(), _helper_deque[jt_idx].begin(), _helper_deque[jt_idx].end());
			std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.begin() + (jt_idx + counter), second_half , compareWithCounter);
			temp.insert(pos, second_half);
		}
		counter += 1;
		
		// if (_helper_deque[jt_idx].size() <= static_cast<size_t>(_size_deque[0])) {
        //     second_half.insert(second_half.end(), _helper_deque[jt_idx].begin(), _helper_deque[jt_idx].end());
        //     std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.end() /*begin() + (i + counter + 1)*/, second_half , compareWithCounter);
		// 	temp.insert(pos, second_half);
		// 	counter += 1;
		// } else {
		// 	second_half.insert(second_half.end(), _helper_deque[jt_idx].begin(), _helper_deque[jt_idx].end() - _length[0]);
		// 	std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.end()/*begin() + (i + counter + 1)*/, second_half , compareWithCounter);
		// 	temp.insert(pos, second_half);
		// 	counter += 1;
		// }
    }
	print_deque_matrix(temp);
    for (size_t i = 0; i < temp.size(); i++) {
        second_half.clear();
        if (temp[i].size() == static_cast<size_t>(2 * _size_deque[0])) {
            second_half.insert(second_half.end(), temp[i].begin() + _size_deque[0], temp[i].end());
            temp[i].erase(temp[i].begin() + _size_deque[0], temp[i].end());
            std::deque<std::deque<int> >::iterator pos = std::lower_bound(temp.begin(), temp.end(), second_half , compareWithCounter);
            temp.insert(pos, second_half);
        }
    }
	_length.pop_front();
	
    // Debugging output
    // std::cout << "temp:\t" << std::endl;
    // print_deque_matrix(temp);
	// for (std::deque<std::deque<int> >::iterator it = temp.begin(); it != temp.end(); ) {
	// 	if (it->empty()) {
	// 		it = temp.erase(it);
	// 	} else {
	// 		++it;
	// 	}
	// }
    _helper_deque = temp;
	std::cout << "temp: first_half" << std::endl;
	print_deque_matrix(_helper_deque);
    _size_deque.pop_front();
    if (!_size_deque.empty() && _size_deque[0] >= 1) {
        sort_back_deque();
    }
    if (_struggler_deque >= 0) {
        second_half.clear();
        second_half.insert(second_half.end(), _struggler_deque);
        std::deque<std::deque<int> >::iterator pos = std::lower_bound(_helper_deque.begin(), _helper_deque.end(), second_half, compareWithCounter);
        _helper_deque.insert(pos, second_half);
        _struggler_deque = -1;
    }
    // std::cout << "_helper_deque:\t" << std::endl;
    // print_deque_matrix(_helper_deque);
}

/*this function recursively sorts the higher value numbers by comparing pairs
again. the higher one is stored to the top, the numbers from the other deque
go to the back. if there is an odd number of input it is stored in temp is
yppended to the last deque. after that the empty deques are deleted the comparison 
of the first elements continues in the same way until there are only two deques 
left. The size of the first deque will be saved to use it for the actual sorting
of the numbers.*/
void	PmergeMe::sort_deque_first() {
	std::deque<int> temp;
	int	size = -1;

	temp.push_back(-1);
	if (_helper_deque.size() % 2 == 1) {
		temp = _helper_deque.back();
		_helper_deque.erase(_helper_deque.end() - 1);
	}
	std::cout << "print length:\t" << _helper_deque.size() << std::endl;
	for (size_t i = 0; i < _helper_deque.size(); i++) {
		if (i % 2 == 0) {
			if (_helper_deque[i][0] > _helper_deque[i + 1][0]) {
				_helper_deque[i].insert(_helper_deque[i].end(), _helper_deque[i + 1].begin(), _helper_deque[i + 1].end());
				_helper_deque[i + 1].clear();
				comparisons++;
			} else {
				if (_helper_deque.size() == 2)
					size = _helper_deque[1].size();
				_helper_deque[i + 1].insert(_helper_deque[i + 1].end(), _helper_deque[i].begin(), _helper_deque[i].end());
				_helper_deque[i].clear();
				comparisons++;
			}
		}
	}
	for (std::deque<std::deque<int> >::iterator it = _helper_deque.begin(); it != _helper_deque.end(); ) {
		if (it->size() == 0) {
			it = _helper_deque.erase(it);
		} else {
			++it;
		}
	}
	if (temp[0] > 0) {
		_helper_deque[_helper_deque.size() - 1].insert(_helper_deque[_helper_deque.size() - 1].end(), temp.begin(), temp.end());
		temp.erase(temp.begin(), temp.end());
	}
	if (_helper_deque.size() > 1)
		_length.push_front(_helper_deque.back().size());
	// std::cout << "_length:\t";
	// print_deque(_length);
	if (_helper_deque.size() > 1)
		_size_deque.push_front(_helper_deque[0].size());
	if (size > 0) {
		_size_deque.pop_front();
		_size_deque.push_front(size);
	}
	// print_deque_matrix(_helper_deque);
	// std::cout << "Struggler:\t" << _struggler_deque << std::endl;
	// std::cout << "Länge erster deque:\t" << _size_deque << std::endl;
	while (_helper_deque.size() > 1)
		sort_deque_first();
}

/*this function pairs the input into seperate deques and puts the higher number
to the front of each deque. the deques are stored in the _helper_deque-deque. if 
the numbers of input numbers is odd it saves the last number to the _struggler_deque.
it will be sorted last.*/
void	PmergeMe::pair_deque() {
	if (_input_deque.size() % 2 == 1) {
		_struggler_deque = _input_deque.back();
		_input_deque.erase(_input_deque.end() - 1);
	}
	for (size_t i = 0; i < _input_deque.size() - 1; i++) {
		if (i % 2 == 0) {
			std::deque<int> new_pair;
			if (_input_deque[i] > _input_deque[i + 1]) {
				new_pair.push_back(_input_deque[i]);
				new_pair.push_back(_input_deque[i + 1]);
				comparisons++;
			} else {
				new_pair.push_back(_input_deque[i + 1]);
				new_pair.push_back(_input_deque[i]);
				comparisons++;
			}
			_helper_deque.push_back(new_pair);
		}
	}
	_size_deque.push_front(_helper_deque[0].size());
	// print_deque_matrix(_helper_deque);
	// std::cout << "Struggler:\t" << _struggler_deque << std::endl;
	// std::cout << "Länge erster deque:\t" << _size_deque << std::endl;
}

//Constructor (int, char**)
PmergeMe::PmergeMe(int argc, char** argv): _struggler_deque(-1), _size_input(argc - 1) {
	// check_input(argc - 1, argv + 1);
	double	elapsed_time;
	std::cout << "Before: ";
    for (int i = 0; i < argc - 1; ++i) {
        int value = std::atoi(argv[i]);
        _input_deque.push_back(value);
        //_input_list.push_back(value);
        std::cout << value << " ";
    }
	std::cout << std::endl;
	
	std::clock_t start_deque = std::clock();
	if (argc == 3) {
		if (_input_deque[0] > _input_deque[1])
			std::swap(_input_deque[0], _input_deque[1]);
		comparisons++;
		std::clock_t end_deque = std::clock();
		elapsed_time = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
		std::cout << "After: ";
		for (size_t i = 0; i <= 1; i++) {
			std::cout << _input_deque[i] << " ";
		}
		std::cout << std::endl;
		return ;
	}
	_size_deque.push_front(1);
	_length.push_back(2);
	pair_deque();
	sort_deque_first();
	sort_back_deque();
	std::clock_t end_deque = std::clock();
	elapsed_time = static_cast<double>(end_deque - start_deque) / CLOCKS_PER_SEC;
	std::cout << "After: ";
	for (size_t i = 0; i <= _helper_deque.size() - 1; i++) {
			std::cout << _helper_deque[i][0] << " ";
	}
	std::cout << std::endl;
	std::cout << std::fixed << std::setprecision(6);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << elapsed_time << " sec" << std::endl;
	std::cout << "Comparisons:\t" << comparisons << std::endl;
	is_sorted_deque(argc - 1);
	// sort_list();

    // Debugging: print the resulting deque
    // print_deque(_jacobsthal_deque);
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
