#include <cppunit/ui/text/TestRunner.h>
#include "include/LotteryTests.h"
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
int main()
{
    // Create the event manager and test controller
    CppUnit::TestResult controller;
 
    // Add a listener that colllects test result
    CppUnit::TestResultCollector result;
    controller.addListener( &result );        
 
    CppUnit::BriefTestProgressListener progressListener;
    controller.addListener( &progressListener );  
   
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( LotteryTests::suite() );
    std::cout << "RUNNING LOTTERY TEST SUITE" << std::endl << std::endl << std::endl;
    runner.run(controller);

    // Print test in a compiler compatible format.
    CppUnit::CompilerOutputter outputter( &result, std::cerr );
    outputter.write();
    std::cin.get();
    return result.wasSuccessful() ? 0 : 1;;
}