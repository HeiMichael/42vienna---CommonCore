/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:01:10 by miheider          #+#    #+#             */
/*   Updated: 2024/11/20 00:10:57 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "Error:\nInvalid input" << std::endl;
		return 1;
	}
	
	PmergeMe	sort(argc, argv + 1);
	
	
	return 0;
}
