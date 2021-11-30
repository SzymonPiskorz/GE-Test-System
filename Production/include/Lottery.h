#include <Asserter.h>
#include <set>
#include <utility>
#include <iostream>
#include <tuple>

class Lottery
{
public:
    Lottery();
    std::pair<bool, std::set<int>> validate(std::set<int> t_lotteryNum);
    std::set<int> generate();

private:
};
