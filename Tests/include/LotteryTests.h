#include <TestFixture.h>
#include <TestAssert.h>
#include <TestCase.h>
#include <TestSuite.h>
#include <TestCaller.h>
#include "../../Production/include/Lottery.h"
#include <queue>
#include <set>
class LotteryTests : public CppUnit::TestFixture
{
private:
    Lottery* m_lottery;
    std::set<int> m_lotteryNumbers;
public:
    static CppUnit::Test* suite();
    void setUp();
    void tearDown();
    void lotteryHas6NumbersTest1();
    void lotteryHas6NumbersTest2();
    void lotteryDoesntHave6NumbersTest1();
    void lotteryDoesntHave6NumbersTest2();
    void lotteryNumbersNotInRangeTest();
    void lotteryNumbersInRangeTest();
    void lotteryUniqueNumbersTest();
    void lotteryNoUnqiueNumbersTest();
};