//Module Implementation Unit can be many
#include <iostream>
#include <ctime>
#include <chrono>

module hello;

void say_hello (const char* n)
{
    auto        time_point = std::chrono::system_clock::now( );
    std::time_t ttp        = std::chrono::system_clock::to_time_t (time_point);
    
    std::string thetime = std::ctime (&ttp);
    thetime.erase(thetime.find('\n', 0), 1);
    
    std::string outTime = std::string("[") + thetime + std::string("] ");
    std::cout << outTime << n << std::endl;
}
