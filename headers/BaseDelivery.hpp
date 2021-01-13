#ifndef BASE_DELIV_HPP
#define BASE_DELIV_HPP

#include "Base.hpp"
#include "Base2.hpp"

class BaseDelivery
    : virtual public Base
    , virtual public Base2
{
    int a {0};

   public:
    virtual void       add( )    = 0;
    virtual const int& getVal( ) = 0;
};

#endif  // BASE_DELIV_HPP
