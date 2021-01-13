#ifndef SMART_POINTERS_HPP
#define SMART_POINTERS_HPP

#include "pch.hpp"

#include "VariadicTemplate.hpp"

class SP_TestClass
{
    int a {0};

   public:
    const int& GetVal( ) { return a; }
    void       SetVal (const int& newVal) { a = newVal; }
};

class SmartPointer
{
   public:
   void addVal (variadicTemplate::Ref<SP_TestClass> spTestClass, const int& val){
       spTestClass->SetVal(val);
   }
};

#endif  // #define SMART_POINTERS_HPP
