/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 09:09:03 by miheider          #+#    #+#             */
/*   Updated: 2024/10/16 13:32:45 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

void    input_times_ten(double &input) {
    input *= 10;
}

void    input_div_ten(float &input) {
    input /= 10;
}

void    input_times_two(int &input) {
    input *= 2;
}

void    increment_two(char &input) {
    input += 2;
}


int main( void ) {
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#01                  test one                     |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        char ar[] = {'a', 'b', 'c', 'R'};
        int arr[] = {1, 2, 5, 564};
        float arra[] = {2.75f, 8.745f, -3.158f, -0.5448f};
        double array[] = {7.546, -87.568, 9.46521, 777.777};
        
        std::cout << ar[0] << std::endl;
        std::cout << arr[1] << std::endl;
        std::cout << arra[2] << std::endl;
        std::cout << array[3] << std::endl;
        std::cout << std::endl;

        increment_two(ar[0]);
        input_times_two(arr[1]);
        input_div_ten(arra[2]);
        input_times_ten(array[3]);
        
        std::cout << ar[0] << std::endl;
        std::cout << arr[1] << std::endl;
        std::cout << arra[2] << std::endl;
        std::cout << array[3] << std::endl;
    }
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#01                  test two                     |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        char ar[] = {'a', 'b', 'c', 'R'};
        int arr[] = {1, 2, 5, 564};
        float arra[] = {2.75f, 8.745f, -3.158f, -0.5448f};
        double array[] = {7.546, -87.568, 9.46521, 777.777};

        ::iter(ar, sizeof(ar) / sizeof(ar[0]), increment_two);
        ::iter(arr, sizeof(arr) / sizeof(arr[0]), input_times_two);
        ::iter(arra, sizeof(arra) / sizeof(arra[0]), input_div_ten);
        ::iter(array, sizeof(array) / sizeof(array[0]), input_times_ten);
        
        std::cout << ar[0] << "\t" << ar[1] << "\t" << ar[2] << "\t" << ar[3] << std::endl;
        std::cout << arr[0] << "\t" << arr[1] << "\t" << arr[2] << "\t" << arr[3] << std::endl;
        std::cout << arra[0] << "\t" << arra[1] << "\t" << arra[2] << "\t" << arra[3] << std::endl;
        std::cout << array[0] << "\t" << array[1] << "\t" << array[2] << "\t" << array[3] << std::endl;
    }
    return 0;
}

