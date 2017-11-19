#include <iostream>
#include <assert.h>
#include <vector>

#include "FileLog.hpp"
#include "Console.hpp"
#include "Timestamp.hpp"
#include "Timer.hpp"

using namespace debug_tools;

void function(){

    FileLog & log = FileLog::GetInstance("whatever.txt");
    log.Log(WARNING, "That a warning dude");

}

int main(int argc, char ** argv){
    /* Testing timer */
    Timer timer;
    timer.Start();

    /* Testing console debugging */
    Console(INFO, "Hello!");
    Console(WARNING, "That's a warning!");
    Console(CRITICAL, "Tread lightly...");
    Console(FATAL, "That's it! I am out.", DARK_BLUE);

    std::cout << "---------------" << std::endl;

    /* Testing custom text print */
    CustomPrint(std::cout, "custom print1\n");
    CustomPrint(std::cout, "custom print2\n", DARK_YELLOW);
    CustomPrintHex(std::cerr, 254);
    CustomPrintHex(std::cerr, -253, DARK_PURPLE);
    CustomPrintHex(std::cout, 1.3);
    CustomPrintHex(std::cout, -200.3, BLUE);

    ConsoleInfo("i", 5);
    ConsoleInfo("i", 5, "j", 6);
    ConsoleInfoL(CRITICAL, "Loop arguments out of bounds", "i", -1, "j", -4);

    std::cout << "---------------" << std::endl;

    /* Testing log file */
    FileLog & log = FileLog::GetInstance("log.txt");
    log.Log(INFO, "This is a piece of information!");

    function();

    /* Testing timestamp */
    Timestamp_t date = GetFullTimestamp();
    ConsoleInfoL(INFO, "Timestamp",
        "Year", date.year,
        "Month", date.month,
        "Day", date.day,
        "Hour", date.hour,
        "Minutes", date.minutes,
        "Sec", date.sec,
        "Msec", date.msec);

    std::cout << "---------------" << std::endl;
    
    timer.Stop();
    Console(INFO, "Time: " + timer.ToString() + " ms");

    Console(INFO, "Epoch time: " + std::to_string(GetSecondsSinceEpoch()) + " s");
    Console(INFO, "Epoch time: " + std::to_string(GetMSecondsSinceEpoch()) + " ms");

    std::cout << "---------------" << std::endl;

    /* Testing vector print */
    std::vector<double> test = {1.0 ,1.2, 1.3, 1.4};
    Print1dVector(test);
    std::vector<std::string> test2 = {"a", "b", "c"};
    Print1dVector(test, false);
   
    log.Log(FATAL, "Fatal error. exiting..."); 

#ifdef _WIN32
	system("pause");
#endif

    return 0;
}
