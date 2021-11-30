#include "LotteryTests.h"

void LotteryTests::setUp()
{
    m_lottery = new Lottery();
}

void LotteryTests::tearDown()
{
    delete m_lottery;
}

void LotteryTests::lotteryHas6NumbersTest1()
{
    m_lotteryNumbers = { 2, 4, 34, 7, 45, 21};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() == 6);
    CPPUNIT_ASSERT(isValid == true);

    std::cout << "LOTTERY HAS 6 NUMBERS TEST 1 PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryHas6NumbersTest2()
{
    m_lotteryNumbers = m_lottery->generate();

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() == 6);
    CPPUNIT_ASSERT(isValid == true);

    std::cout << "LOTTERY HAS 6 NUMBERS TEST 2 PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryDoesntHave6NumbersTest1()
{
    m_lotteryNumbers = { 2, 4, 34, 7,  21};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() != 6);
    CPPUNIT_ASSERT(isValid == false);

    std::cout << "LOTTERY DOESN'T HAVE 6 NUMBERS TEST 1 PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryDoesntHave6NumbersTest2()
{
    m_lotteryNumbers = { 2, 4, 34, 7, 45, 21, 9};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() != 6);
    CPPUNIT_ASSERT(isValid == false);
    
    std::cout << "LOTTERY DOESN'T HAVE 6 NUMBERS TEST 2 PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryNumbersInRangeTest()
{
    m_lotteryNumbers = { 2, 4, 34, 7, 45, 21};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;
    std::set<int>::iterator itr;


    for (itr = m_lotteryNumbers.begin(); itr == m_lotteryNumbers.end(); itr++)
    {
        CPPUNIT_ASSERT(*itr >= 1 && *itr <= 46);
    }
    CPPUNIT_ASSERT(isValid == true);

    std::cout << "LOTTERY NUMBERS IN RANGE TEST PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryNumbersNotInRangeTest()
{
    m_lotteryNumbers = { 200, 666, -34, -7, 450, 210};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;
    std::set<int>::iterator itr;


    for (itr = m_lotteryNumbers.begin(); itr == m_lotteryNumbers.end(); itr++)
    {
        CPPUNIT_ASSERT(*itr >= 1 && *itr <= 46);
    }
    CPPUNIT_ASSERT(isValid == false);

    std::cout << "LOTTERY NUMBERS NOT IN RANGE TEST PASSED" << std::endl; 
    std::cout << std::endl << std::endl;
}

void LotteryTests::lotteryUniqueNumbersTest()
{
     m_lotteryNumbers = { 2, 4, 34, 7, 45, 21};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() == 6);
    CPPUNIT_ASSERT(isValid == true);

    std::cout << "LOTTERY UNIQUE NUMBERS TEST PASSED" <<std::endl;
}

void LotteryTests::lotteryNoUnqiueNumbersTest()
{
     m_lotteryNumbers = { 2, 4, 34, 7, 45, 45};

    bool isValid = m_lottery->validate(m_lotteryNumbers).first;
    m_lotteryNumbers = m_lottery->validate(m_lotteryNumbers).second;

    CPPUNIT_ASSERT(m_lotteryNumbers.size() != 6);
    CPPUNIT_ASSERT(m_lotteryNumbers.size() == 5);
    CPPUNIT_ASSERT(isValid == false);

    std::cout << "LOTTERY NO UNIQUE NUMBERS TEST PASSED" <<std::endl;
}

CppUnit::Test* LotteryTests::suite()
{
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "LotteryTests" );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryHas6NumbersTest", 
    &LotteryTests::lotteryHas6NumbersTest1 ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryHas6NumbersTest", 
    &LotteryTests::lotteryHas6NumbersTest2 ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryDoesntHave6NumbersTest", 
    &LotteryTests::lotteryDoesntHave6NumbersTest1 ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryDoesntHave6NumbersTest", 
    &LotteryTests::lotteryDoesntHave6NumbersTest2 ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryNumbersInRangeTest", 
    &LotteryTests::lotteryNumbersInRangeTest ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryNumbersNotInRangeTest", 
    &LotteryTests::lotteryNumbersNotInRangeTest ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryUniqueNumbersTest", 
    &LotteryTests::lotteryUniqueNumbersTest ) );

    suiteOfTests->addTest( new CppUnit::TestCaller<LotteryTests>( 
    "lotteryNoUnqiueNumbersTest", 
    &LotteryTests::lotteryNoUnqiueNumbersTest ) );

    return suiteOfTests;
}
