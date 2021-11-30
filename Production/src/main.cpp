#include "../../Production/include/Lottery.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

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

        if(lottery.validate(lotteryNums).first)
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
        while (inputNum > 0)
        {
           int numInput;
           std::cin >> numInput;
           lotteryNums.insert(numInput);
           inputNum--;
        }
        if(lottery.validate(lotteryNums).first)
        {
            std::cout << "This is a valid lottery number" << std::endl;
        }
        else
        {
            std::cout << "This is not a valid lottery number" << std::endl;
        }
    }
    
    std::cin.get();
    return 0;
}