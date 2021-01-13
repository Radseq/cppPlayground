#ifndef C20_CONST_X_HPP
#define C20_CONST_X_HPP

#include "pch.hpp"

class c20ConstX
{
    // https://www.modernescpp.com/index.php/c-20-consteval-and-constinit
	/*
	 * only one of consteval, constexpr, or constinit can be used in function specyfic
	 * consteval create and execute in compile time
	 */

   public:
	int           sqrRunTime (const int& n)            { return n * n; }
	consteval int sqrCompileTime (const int& n)        { return n * n; }
	constexpr int sqrRunOrCompileTime (const int& n)   { return n * n; }

    c20ConstX( ) { /*int asdasd =  sqrCompileTime(50);*/ }; // consteval cannot be applied to destructors or functions which allocate or deallocate
	~c20ConstX( ) { };
	
	void execute( )
	{
		const int x = 100;

		int prod4 = sqrRunTime (x);
		//int prod5 = sqrCompileTime (x);  // ERROR x should be const also sqrCompileTime wont execute in member function
		int prod6 = sqrRunOrCompileTime (x);

        // constexpr int prod1 = sqrRunTime(100);
        // constexpr int prod2 = sqrCompileTime (100);
		// constexpr int prod3 = sqrRunOrCompileTime (100);
        // OK
        /*
        * constexpr dont work in class members but why? member class dont exists in compile time? 
        * stack overflow:
        * Because they are member variables that are initialized at runtime and cannot be evaluated until they are initialized. – Captain Obvlious Dec 10 '14 at 19:08
        */
	}

};

#endif  // #define C20_CONST_X_HPP
