#ifndef SOMECLASSTOVEC_H
#define SOMECLASSTOVEC_H

#include <iostream>
#include <vector>

class SomeClassTOVec
{
   public:
	SomeClassTOVec( ) { }

	~SomeClassTOVec( ) { };
};

class SomeClassTOVecRefTest
{
   public:
	SomeClassTOVecRefTest( ) { }

	~SomeClassTOVecRefTest( ) { };
};

class SomeClassVecTest
{
	int    m_int {0};
	double m_double {0};
	// SomeClassTOVec m_Vec;
	SomeClassTOVec m_SomeClassToVector;

	const SomeClassTOVecRefTest& m_SomeClassToVectorRef;

	std::vector<SomeClassTOVec> m_vecSomeClassTOVec;

   public:
	/*
	 SomeClassVecTest (const int& Int, const double& Double, const SomeClassTOVec&& vec)
		 : m_int (Int)
		 , m_double (Double)
		 , m_Vec (vec)
	 {
	 }*/

	SomeClassVecTest (const int& Int, const double& Double)
		: m_int (Int)
		, m_double (Double)
		, m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))
	{
	}

	SomeClassVecTest (const SomeClassTOVec& classToVec)
		: m_SomeClassToVector (classToVec)
		, m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))
	{
	}

	SomeClassVecTest (const SomeClassTOVecRefTest& classToVecRef)
		: m_SomeClassToVectorRef (classToVecRef)
	{
	}

	SomeClassVecTest (const std::vector<SomeClassTOVec>& vecSomeClassToVec)
		: m_vecSomeClassTOVec (vecSomeClassToVec)
		, m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))
	{
	}

	SomeClassVecTest (const std::vector<SomeClassTOVec>&& vecSomeClassToVec)
		: m_vecSomeClassTOVec (std::move(vecSomeClassToVec))
		, m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))
	{
	}

	SomeClassVecTest (const SomeClassVecTest&)
		: m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))  // a copy constructor
	{
		;

		std::cout << "copy constructor"
				  << "\n";
	}

	SomeClassVecTest& operator= (const SomeClassVecTest&)  // a copy assignment
	{
		std::cout << "copy assignment"
				  << "\n";
		return *this;
	}

	SomeClassVecTest (SomeClassVecTest&&)
		: m_SomeClassToVectorRef (*new SomeClassTOVecRefTest( ))  // a move constructor
	{
		std::cout << "move constructor"
				  << "\n";
	}

	SomeClassVecTest& operator= (SomeClassVecTest&&)  // a move assignment
	{
		std::cout << "move assignment"
				  << "\n";
		return *this;
	}

	~SomeClassVecTest( ) { };
};

#endif  // SOMECLASSTOVEC_H