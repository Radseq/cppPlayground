#include "../headers/Delivery.hpp"

void       Delivery::add (const int&& val) { a = val; };
const int& Delivery::getVal( ) { return a; };