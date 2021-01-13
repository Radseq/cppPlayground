//Module Implementation Unit 
//can be many Implementation of interface
//dont has export keyword
//if oblect is in namespace xxx use xxx::

#include <iostream>

module testClass;

namespace TestNamespace{
    myClass::myClass(const int& val) : a (val) 
    {}

    const int& myClass::getAval()
    {
        return a; 
    }

    void myClass::setVal(const int& newVal)
    {
        a = newVal;
    }

    void print(myClass* cl)
    {
        std::cout << "myClass a value: " << cl->a << std::endl;
    }
}

// or const int& TestNamespace::myClass::getAval() { return a; }
