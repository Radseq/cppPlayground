//Module Implementation Unit can be many
#include <iostream>

module hello;

void say_hello (const char* n)
{
    std::cout << "Hello, " << n << '!' << std::endl;
}
