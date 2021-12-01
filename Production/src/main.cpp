#include "../../Production/include/Lottery.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <limits>

const auto LineLimit = std::numeric_limits<std::streamsize>::max();

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));
    Lottery lottery;
    int inputNum = 6;
    bool autoGen = false;
    std::set<int>lotteryNums;
    std::string input;

    std::cout << "Type in True if you want to auto generate the numbers and anything else if you dont" << std::endl;
    std::cin >> input;

    if(input == "True")
        autoGen = true;

    if(autoGen)
    {
        lotteryNums = lottery.generate();

        std::set<int>::iterator it = lotteryNums.begin();

        if(lottery.validate(lotteryNums))
        {
            std::cout << "This is a valid lottery number" << std::endl;
        }
        else
        {
            std::cout << "This is not a valid lottery number" << std::endl;
        }

        while (it != lotteryNums.end())
        {
        std::cout << *it << std::endl;
           it++;
        }
    }
    else
    {
        std::cout << "Enter 6 unique numbers in a range from 1 to 46" << std::endl;
        while (inputNum > 0)
        {
           int numInput;
           std::cin >> numInput;
           lotteryNums.insert(numInput);
           inputNum--;
        }
        if(lottery.validate(lotteryNums))
        {
            std::cout << "This is a valid lottery number" << std::endl;
        }
        else
        {
            std::cout << "This is not a valid lottery number" << std::endl;
        }
    }
    std::cin.ignore(LineLimit, '\n');
    std::cin.get();

    return 0;
}