/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:00:04 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 11:44:00 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {
    {
        std::cout << "TEST1" << std::endl;
        std::cout << std::endl;
        try {
            Span a(10);
            
            a.addNumber(14);
            a.addNumber(31);
            a.addNumber(17);
            a.addNumber(9);
            a.addNumber(1);
            std::cout << "size:\t\t" << a.get_size() << std::endl;
            std::cout << "shortest span:\t" << a.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << a.longestSpan() << std::endl;
            a.fill(2);
            a.fill(20, 500);
            
        } catch (Span::CanNotAddANumberException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooFewNumbersInVectorException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::VectorIsEmptyException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeTooHighException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooManyNumbersAttemptException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeOverflowException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::MemoryAllocationException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "TEST2" << std::endl;
        std::cout << std::endl;
        try {
            Span b(1000);
            
            b.addNumber(14);
            b.addNumber(31);
            b.addNumber(17);
            b.addNumber(9);
            b.addNumber(1);
            std::cout << "size:\t\t" << b.get_size() << std::endl;
            std::cout << "shortest span:\t" << b.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << b.longestSpan() << std::endl;
            b.fill(2);
            b.fill(20, 500);
        } catch (Span::CanNotAddANumberException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooFewNumbersInVectorException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::VectorIsEmptyException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeTooHighException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooManyNumbersAttemptException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeOverflowException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::MemoryAllocationException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "TEST3" << std::endl;
        std::cout << std::endl;
        try {
            Span b(100000);
            
            b.fill(100000, 1000000);
            std::cout << "size:\t\t" << b.get_size() << std::endl;
            std::cout << "shortest span:\t" << b.shortestSpan() << std::endl;
            std::cout << "longest span:\t" << b.longestSpan() << std::endl;
        } catch (Span::CanNotAddANumberException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooFewNumbersInVectorException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::VectorIsEmptyException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeTooHighException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::TooManyNumbersAttemptException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::RangeOverflowException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        } catch (Span::MemoryAllocationException& e) {
            std::cout << "Error\n" << e.what() << std::endl;
        }
    }
    return 0;
}
