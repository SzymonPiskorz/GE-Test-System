#include "../../Production/include/Lottery.h"

Lottery::Lottery()
{

}

bool Lottery::validate(std::set<int> t_lotteryNum)
{
    bool valid = false;

    if(t_lotteryNum.size() == 6)
    {
        std::set<int>::iterator it = t_lotteryNum.begin();
        while (it != t_lotteryNum.end())
        {
           if(*it >=1 && *it <= 46)
           {
               valid = true;
           }
           else
           {
               return false;
           }
           it++;
        }
    }
    return valid;
}

std::set<int> Lottery::generate()
{
    std::set<int> lotteryNums;

    while (lotteryNums.size() < 6)
    {
        int randNum = rand() % 46 + 1;
        lotteryNums.insert(randNum);
    }

    return lotteryNums;
}