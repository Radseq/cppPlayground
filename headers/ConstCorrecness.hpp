#ifndef CONST_CORRECTNESS_HPP
#define CONST_CORRECTNESS_HPP

#include "ConstCorrTestClass.hpp"
#include "pch.hpp"

class ConstCorrecness
{
	void func1 (std::string& str) { str = "Func 1 string"; }

	void PassConstToNonConst( )
	{
		const std::string str = "some string";
		// func1 (str);  // obviously don't work cause const val cannot be changed
	}

	void pointerValConst (const std::string* val)
	{
		std::cout << "const value pointer adr = " << val << std::endl;
		std::cout << "const value pointer string val = " << *val << std::endl;
		std::string* testVal = new std::string ("someNewStringValue");
		// work because pointer itself can be changet (replaced here) because its not const, const is only value where
		// pointer pointing
		val = testVal;

		std::cout << "const value pointer adr = " << val << std::endl;

		std::cout << "const value pointer string val = " << *val << std::endl;
		// dont work because value is const
		// std::string test2 ("newStringVal");
		// val = &testVal;
	}

	void constPointer (std::string* const val)
	{
		std::cout << "const pointer string val = " << *val << std::endl;
		// dont work because pointer is cosnt
		// std::string* testVal = new std::string ("someNewStringValue");
		// val = testVal;
		// std::cout << "pointer string val = " << *val << std::endl;
		std::string newVal ("constPointerNewVal");
		*val = newVal;  // we can because data where pointer is pointing is not const
		std::cout << "const pointer string val = " << *val << std::endl;
	}

	void constPointerConstValue (const std::string* const val)
	{
		std::cout << "const pointer const string val = " << *val << std::endl;
		// cant change pointer because is const
		// std::string* testVal = new std::string ("someNewStringValue");
		// val = testVal;
		// cant change value because const pointer is pointing to const value
		// std::string newVal ("constPointerNewVal");
		//*val = newVal;
		// std::cout << "const pointer string val = " << *val << std::endl;
	}

	void ConstClassOper (const ConstCorrTestClass& testClass)
	{
		// Cant because testClass is const and method cant change state of obj.
		// testClass.SetId (4);

		// hmmmmmm, ConstCorrTestClass is const
		// but GetId method has const reference, so there is no possible to modify using GetId.
		// int id = testClass.GetId( );
		// but function itself can modify value of class (other than id in this ex.) 
		// thats why this wont work 

		int id = testClass.GetId2( );

		int mutVal = testClass.GetMutabledValue( );
	}

	void constClass( )
	{
		ConstCorrTestClass tc { };
		ConstClassOper (tc);  // send as const reference
	}

   public:
	void execute( )
	{
		std::string* str = new std::string ("smt");
		pointerValConst (str);
		constPointer (str);
		constPointerConstValue (str);
		constClass( );
	};
};

#endif  // CONST_CORRECTNESS_HPP
