#ifndef No_DISCARD_HPP
#define No_DISCARD_HPP

#include "pch.hpp"

class [[nodiscard]] NoDiscardClass  // obviously work same for struct
{
};

class NoDiscard
{
	int noDiscard1 = 5;
	int normalVal  = 10;

	NoDiscardClass nDc;

   public:
	[[nodiscard ("rvalue not used, is not assigned to lvalue")]] const int& GetNoDiscardVal( );

	const int& GetNormalVal( );

	NoDiscardClass        testNoDiscardClass( );
	const NoDiscardClass& testNoDiscardClass2( );
};

NoDiscardClass        NoDiscard::testNoDiscardClass( ) { return nDc; }
const NoDiscardClass& NoDiscard::testNoDiscardClass2( ) { return nDc; }

const int& NoDiscard::GetNoDiscardVal( ) { return noDiscard1; }
const int& NoDiscard::GetNormalVal( ) { return normalVal; }
// here i can return int but why? why make allocate 4 byes and return copied value??

#endif  // No_DISCARD_HPP