#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#01          basic test form subject              |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;
    }
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#02                costum test                    |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        try {
            Array<int> popi(5);
            std::cout << popi.size() << std::endl;
    
            popi[0] = 12;
            std::cout << popi[0] << std::endl;
            popi[6] = 7;
        } catch (std::exception& e) {
            std::cout << "Error:\n" << e.what() << std::endl;
        }
    }
    {
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "|#03                another test                   |" << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        try {
            Array<int> hiphop;
            std::cout << hiphop.size() << std::endl;
            hiphop[0] = 12;
        } catch (std::exception& e) {
            std::cout << "Error:\n" << e.what() << std::endl;
        }
    }
    return 0;
}
