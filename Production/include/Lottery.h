#include <set>
#include <utility>
#include <iostream>
#include <tuple>

class Lottery
{
public:
    Lottery();
    bool validate(std::set<int> t_lotteryNum);
    std::set<int> generate();
};
