/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miheider <miheider@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:51:41 by miheider          #+#    #+#             */
/*   Updated: 2024/10/21 12:49:51 by miheider         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << "Test 1 --- subject example" << std::endl;
        std::cout << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    {
        std::cout << std::endl;
        std::cout << "Test 2 --- subject example with a list" << std::endl;
        std::cout << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);                        //push_back instead of push
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;    //back instead of top
        mstack.pop_back();                          //pop_back instead of pop
        std::cout << mstack.size() << std::endl;

        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);

        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite) {
            std::cout << *it << std::endl;
            ++it;
        }

        std::list<int> s(mstack);
    }
    {
        std::cout << "Test 3 --- costum test" << std::endl;
        std::cout << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        mstack.push(23);
        mstack.push(123);
        mstack.push(223);
        mstack.push(323);
        mstack.push(423);
        mstack.push(523);
        mstack.push(623);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        std::cout << "print iterator:\t" << *it << std::endl;
        ++it;
        ++it;
        std::cout << "print iterator:\t" << *it << std::endl;
        it = mstack.begin();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
return 0;
}
