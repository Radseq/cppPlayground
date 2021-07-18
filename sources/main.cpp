#include "../VectorTets/SomeClassTOVec.hpp"
#include "../headers/BaseDelivery.hpp"
#include "../headers/ConstCorrecness.hpp"
#include "../headers/Delivery.hpp"
#include "../headers/Lambdas.hpp"
#include "../headers/NoDiscard.hpp"
#include "../headers/Raii.hpp"
#include "../headers/SmartPointer.hpp"
#include "../headers/StringIiterals.hpp"
#include "../headers/c20ConstX.hpp"
#include "../headers/classthrowOnConstructor.hpp"

void passSP (SP_TestClass* sp) { auto sdsd = sp->GetVal( ); }

void passSP2 (variadicTemplate::Ref<SP_TestClass> sp) { auto sdsd = sp->GetVal( ); }

void smt (Base* const base) { base->add (4); }

// declaration, definition is after main function
void screwWithSmartPointers( );
void PushBackVSEmplaceBack( );
void optionalTest( );

int main( )
{
	StringIiterals  sl { };
	Lambdas         lam { };
	c20ConstX       constExp { };
	ConstCorrecness cc { };

	NoDiscard nd { };

	/*auto val =*/nd.GetNoDiscardVal( );  // unlock to not have warning
	nd.GetNormalVal( );

	/*auto ndClass =*/nd.testNoDiscardClass( );  // unlock to not have warning
	nd.testNoDiscardClass2( );  // here no warning because function has no return object value, its return const
								// reference of object

	sl.print( );

	lam.Func( );

	screwWithSmartPointers( );

	constExp.execute( );

	// constexpr int prod1 = sqrRunTime(100); //ERROR prod1 must have value in comile time (constexpr) but dont have
	// because use sqrRunTime
	constexpr int prod2 = constExp.sqrCompileTime (100);
	constexpr int prod3 = constExp.sqrRunOrCompileTime (100);

	int x = 100;

	int prod4 = constExp.sqrRunTime (x);
	// int prod5 = sqrCompileTime (x);  // ERROR x should be const
	int prod6 = constExp.sqrRunOrCompileTime (x);

	// constinit can be applied to variables with static storage duration or thread storage duration.
	constexpr auto res1 = constExp.sqrCompileTime (5);  // have static storage duration
	// constinit auto res2 = constExp.sqrCompileTime (5);  //  error: local variable cannot
	// be declared 'constinit'

	// ERROR its not global (namespace) variables, static variables, or static class members
	// to work put ex. static before constinit
	// constinit auto res2 = constExp.sqrCompileTime  (5);

	// thread_local variables have thread storage duration.
	// Thread local data is created for each thread that uses this data
	// thread_local data exclusively belongs to the thread. They are created at its first usage and its lifetime is
	// bound to the lifetime of the thread it belongs to. Often thread local data is called thread local storage.
	constinit thread_local auto res3 = constExp.sqrCompileTime (5);  // has thread storage duration.

	constexpr int        constexprVal = 1000;
	static constinit int constinitVal = 1000;  // work if i use static
	auto                 val          = 1000;
	const auto           res          = constExp.sqrRunTime (val);
	std::cout << "res: " << res << std::endl;

	// std::cout << "res: " << ++res << std::endl;                       ERROR it's obvious because res is const
	// std::cout << "++constexprVal++: " << ++constexprVal << std::endl; ERROR constexprVal is always immediate and cant
	// be modifyed
	std::cout << "++constinitVal++: " << ++constinitVal
			  << std::endl;  // (3) does not imply constness like const, constexpr

	constexpr auto localConstexpr = 1000;  // (4)
	// constinit auto localConstinit = 1000; ERROR its not global (namespace) variables, static variables, or static
	// class members

	cc.execute( );

	PushBackVSEmplaceBack( );

	optionalTest( );

	Raii raii (10);
	Raii raii2 (x);
	Raii raii3 (std::move (raii2));  // run move constructor

	Raii raii4 = std::move (raii);  // also run move constructor, we construct object not assignment it

	Raii raii5 = std::move (Raii (30));  // also run move constructor, we construct object not assignment it

	Raii raii6 (60);

	raii =
		std::move (raii5);  // call move assignment, without std::move it will call copy, but we delete copy assignment

	return 1;
}

void optionalTest( )
{
	std::optional<classthrowOnConstructor> optTest;

	if (optTest) int asdsaf;  // not entered

	try
	{
		optTest.emplace (true);  // throw error on constructor
								 // std::optional is useless when exception is throw in constructor.
	}
	catch (const std::exception& e)
	{
		std::cout << " e.what() = " << e.what( ) << std::endl;
	}

	if (optTest) int fasdada;  // not enter

	optTest.reset( );
	optTest.emplace (false);

	if (optTest) int fasdada;  // enter
}

void screwWithSmartPointers( )
{
	auto sumNumbers = variadicTemplate::sum (10, 20, 30);

	auto spTestClassObj = variadicTemplate::CreateRef<SP_TestClass>( );
	spTestClassObj->SetVal (10);

	SmartPointer sp { };
	sp.addVal (spTestClassObj, sumNumbers);

	int spTestClassVal = spTestClassObj->GetVal( );

	auto spTestClassObj2 = variadicTemplate::CreateRef<SP_TestClass>( );

	spTestClassObj2 = spTestClassObj;

	int references = spTestClassObj.use_count( );
	std::cout << "SP_TestClass ref count: " << references << std::endl;
	std::cout << "Pass pointer from smart pointer to see smart ptr reference count" << std::endl;
	passSP (spTestClassObj.get( ));
	references = spTestClassObj.use_count( );
	std::cout << "ref count after pass pointer * (not smart pointer ptr): " << references << std::endl;
	std::cout << "now pass whole smart pointer to function (not used get()): " << std::endl;
	passSP2 (spTestClassObj);  // in fuction reference count + 1
	references = spTestClassObj.use_count( );
	std::cout << "SP_TestClass ref count: " << references << std::endl;

	// multi inheritence example
	/*
	Base is abstract class with method add()
	Base2 is abstract class with method const int& getVal( )
	BaseDelivery is abstract class inheritence methods from Base and Base2
	Delivery is class which inheritence BaseDelivery
	implement add(), const int& getVal( )
	and has own method: setVal (const int&& val)
	*/

	Delivery deliv;

	deliv.setVal (2);

	Base* base = &deliv;
	smt (base);

	auto aaa = deliv.getVal( );

	variadicTemplate::Ref<BaseDelivery> baseSmartPointer = variadicTemplate::CreateRef<Delivery>( );
	baseSmartPointer->add (3);
	int res = baseSmartPointer->getVal( );
}

// https://isocpp.org/blog/2018/02/quick-q-whats-the-difference-between-stdmove-and-stdforward
void overloaded (int const& arg) { std::cout << "by lvalue\n"; }
void overloaded (int&& arg) { std::cout << "by rvalue\n"; }

template <typename t>
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding (t&& arg)
{
	std::cout << "via std::forward: ";
	overloaded (std::forward<t> (arg));
	std::cout << "via std::move: ";
	overloaded (std::move (arg));  // conceptually this would invalidate arg
	std::cout << "by simple passing: ";
	overloaded (arg);
}

void PushBackVSEmplaceBack( )
{
	std::vector<SomeClassVecTest> vec;
	SomeClassVecTest              someClassVecTest (1, 2);
	SomeClassTOVec                someClassTOVec {1};

	std::cout << "\n\n\n\n"
			  << "EMPLACE BACK TEST:" << std::endl;

	vec.emplace_back (std::forward<SomeClassVecTest> (someClassVecTest));  // move constructor
	std::cout << "std::forward<SomeClassVecTest> = move constructor" << std::endl;
	vec.emplace_back (std::move (someClassVecTest));  // move constructor + copy constructor
	std::cout << "std::move (someClassToPushBack) = move + copy contructor" << std::endl;
	vec.emplace_back (std::forward<int> (10), std::forward<double> (29));  // copy 2x constructor
	std::cout << "std::forward<int> (10), std::forward<double> (29) = copy constructor x2" << std::endl;

	vec.emplace_back (10, 29);  // move constructor
	std::cout << "(10, 29) = no print" << std::endl;

	vec.emplace_back (std::forward<SomeClassTOVec> (someClassTOVec));  // 4x copy constructor
	std::cout << "std::forward<SomeClassTOVec> = 4x copy constructor!" << std::endl;

	vec.emplace_back (std::move (SomeClassTOVec (9)));  // no prints
	std::cout << "std::move (SomeClassTOVec( )) = no prints!" << std::endl;
	vec.emplace_back (SomeClassTOVec (11));  // no prints
	std::cout << "SomeClassTOVec( ) = no prints" << std::endl;

	// vec.emplace_back ((std::forward<int> (10), std::forward<double> (29)));  // no prints
	// std::cout << "(std::forward<int> (10), std::forward<double> (29)) = no prints wtf" << std::endl;

	std::cout << "\n\n\n\n"
			  << "PUSH BACK TEST:" << std::endl;
	vec.push_back (std::forward<SomeClassVecTest> (someClassVecTest));  // move constructor
	std::cout << "std::forward<SomeClassVecTest> = move constructor" << std::endl;
	vec.push_back (std::move (someClassVecTest));  // 1x move 8x copy
	std::cout << "std::move (someClassToPushBack) = 1x move 8x copy" << std::endl;
	vec.push_back ({10, 29});  // move constructor
	std::cout << "{10, 29} = move constructor" << std::endl;

	vec.push_back (std::forward<SomeClassTOVec> (someClassTOVec));  // move constructor
	std::cout << "std::forward<SomeClassTOVec> = move constructor" << std::endl;

	vec.push_back (std::move (SomeClassTOVec (245)));  //  move constructor
	std::cout << "std::move (SomeClassTOVec( )) = move constructor" << std::endl;
	vec.push_back (SomeClassTOVec (10));  // move constructor
	std::cout << "SomeClassTOVec( ) = move constructor" << std::endl;

	variadicTemplate::forward (vec, someClassVecTest);
	variadicTemplate::forward (vec, someClassTOVec);
	variadicTemplate::forward (vec, 2, 3);

	std::cout << "\n\n\n\n"
			  << "EMPLACE BACK TEST REF MEMBER:" << std::endl;

	SomeClassTOVecRefTest someClassTOVecRefTest;

	vec.emplace_back (std::forward<SomeClassTOVecRefTest> (someClassTOVecRefTest));  // no print
	std::cout << "std::forward<SomeClassTOVecRefTest> = no print" << std::endl;
	vec.emplace_back (std::move (someClassTOVecRefTest));  // no print
	std::cout << "std::move (someClassTOVecRefTest) = no print" << std::endl;
	vec.emplace_back (std::move (SomeClassTOVecRefTest( )));  // no print
	std::cout << "std::move (SomeClassTOVecRefTest( )) = no prints!" << std::endl;
	vec.emplace_back (SomeClassTOVecRefTest( ));  // 16x copy constructor
	std::cout << "SomeClassTOVecRefTest( ) = 16x copy constructor" << std::endl;

	// vecPushBack.emplace_back (someClassTOVecRefTest);  // we cant do that

	std::cout << "\n\n\n\n"
			  << "PUSH BACK TEST REF MEMBER:" << std::endl;
	vec.push_back (std::forward<SomeClassTOVecRefTest> (someClassTOVecRefTest));  // move constructor
	std::cout << "std::forward<SomeClassTOVecRefTest> = move constructor" << std::endl;
	vec.push_back (std::move (someClassTOVecRefTest));  // move constructor
	std::cout << "std::move (someClassTOVecRefTest) = move contructor" << std::endl;
	vec.push_back (std::move (SomeClassTOVecRefTest( )));  // move constructor
	std::cout << "std::move (SomeClassTOVecRefTest( )) = move constructor" << std::endl;
	vec.push_back (SomeClassTOVecRefTest( ));  // move constructor
	std::cout << "SomeClassTOVecRefTest( ) =  move constructor" << std::endl;

	// variadic template forward

	variadicTemplate::forward (vec, someClassTOVecRefTest);
	SomeClassTOVec              aToVec {1};
	SomeClassTOVec              bToVec {2};
	SomeClassTOVec              cToVec {3};
	std::vector<SomeClassTOVec> vecSomeClassToVec;
	vecSomeClassToVec.push_back (aToVec);
	vecSomeClassToVec.push_back (bToVec);
	vecSomeClassToVec.push_back (cToVec);
	variadicTemplate::forward (vec, vecSomeClassToVec);
	int a321 = 0;

	std::vector<SomeClassVecTest> vec2;
	int                           a = sizeof (vec2);
	SomeClassTOVec                aToVec2 {1};
	a = sizeof (aToVec2);
	variadicTemplate::forward (vec2, aToVec2);
	a             = sizeof (vec2);
	int saffwqwqe = aToVec2.GetVal( );
	int sadsadad  = sizeof (SomeClassVecTest);

	std::cout << "initial caller passes rvalue:\n";
	forwarding (5);
	std::cout << "initial caller passes lvalue:\n";
	int x = 5;
	forwarding (x);
}