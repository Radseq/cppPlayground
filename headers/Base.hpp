#ifndef BASE_CLASS_HPP
#define BASE_CLASS_HPP

class Base
{
   public:
    virtual ~Base( )    = default;
    virtual void add( ) = 0;
};

#endif  // BASE_CLASS_HPP