#include "../headers/Lambdas.hpp"

void Lambdas::Print (const std::string& str) { std::cout << str << std::endl; };

void Lambdas::Print (const int& val) { std::cout << std::to_string (val) << std::endl; };

void Lambdas::Func( )
{
	Print ("\n\n LAMBDA: \n");

	/*
	[capture clause] (parameters) -> return-type
	{
		// body
	}*/
	/*
	[&] – Capture all external variables by reference.

	[=] – Capture all external variables by value

	[x,&y] – Capture x by value and y by reference.
	*/

	int x {lambVal};
	Print ("x = " + std::to_string (x));
	auto newValLambda = [x] (const int& Val) { return x + Val; };

	x = newValLambda (100);

	Print ("x = " + std::to_string (x));

	// pass x as reference and val
	auto lambda2 = [&x] (const int& Val) {
		if (Val == 0) x = 2;
		x = Val + (x * 2);
	};

	lambda2 (x);
	Print ("x = " + std::to_string (x));

	int newX {1};
	// pass newX as reference and parameter int
	auto lambda3 = [&newX] (const int& Val) {
		if (Val == 0) newX = 2;
		newX = Val + (newX * 2);
	};

	lambda3 (x);
	Print ("newX = " + std::to_string (newX));

	// pass newX as reference and x as value
	// and no parameters
	auto lambda4 = [&newX, x]( ) { newX = x + (newX * x); };

	lambda4( );

	Print ("newX = " + std::to_string (newX));

	auto lambda5 = [i = 0]( ) mutable { return ++i; };
	int  lam5Va  = lambda5( );
	Print ("lam5Va = " + std::to_string (lam5Va));
};
