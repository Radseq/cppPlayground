#ifndef BASE2_CLASS_HPP
#define BASE2_CLASS_HPP

class Base2
{
   public:
    virtual ~Base2( )            = default;
    virtual const int& getVal( ) = 0;
};

#endif  // BASE2_CLASS_HPP
