/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:01:10 by miheider          #+#    #+#             */
/*   Updated: 2024/11/21 14:17:36 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	check_input(int argc, char **argv) {
	for (int i = 0; i < argc; i++) {
		char *str = argv[i];
		while (*str == '0')
			str++;
		size_t len = strlen(str);
		if (len == 0) 
			continue;
		for (size_t j = 0; j < len; j++) {
			if (j == 10)
				return 1;
			if (str[j] < '0' || str[j] > '9')
				return 1;
			if (j == 9 && strcmp(str, "2147483647") > 0)
				return 1;
		}
	}
	return 0;
}

int	main(int argc, char **argv) {
	if (check_input(argc - 1, argv + 1) == 1) {
		std::cerr << "Error:\nInvalid input" << std::endl;
		return 1;
	}
		
	PmergeMe	sort(argc, argv + 1);	
	
	return 0;
}
