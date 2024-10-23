/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:11:02 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 10:38:11 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    {
        std::vector<int>	vector_one;

		vector_one.push_back(23);
		vector_one.push_back(12);
		vector_one.push_back(-985);
		vector_one.push_back(0);
		vector_one.push_back(65);
		vector_one.push_back(12);

		try {
			::easyfind(vector_one, 65);
		} catch (NumberNotFoundException& e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
		std::cout << std::endl;
    }
	{
        std::vector<int>	vector_two;

		vector_two.push_back(23);
		vector_two.push_back(12);
		vector_two.push_back(-985);
		vector_two.push_back(0);
		vector_two.push_back(65);
		vector_two.push_back(12);

		try {
			::easyfind(vector_two, 6);
		} catch (NumberNotFoundException& e) {
			std::cout << "Error:\n" << e.what() << std::endl;
		}
    }
	return 0;
}
