#include "../headers/StringIiterals.hpp"

void StringIiterals::stdOut (const std::string& str) { std::cout << str << std::endl; };

void StringIiterals::print( )
{
	// string iiterals its all between "" ex. "Your Name"
	// char* str = "AS\0DFG"; //ISO C++11 does not allow conversion from string literal to

	const char* str = "AS\0DFG";  // print AS because \0 mean null it means end of string
	stdOut (str);
	std::cout << strlen (str) << std::endl;  // print 2 (because AS)

	// const char str2 [11] = "ASD\0FGHJKZL";  // initializer-string for char array is too long..... because of (\0)
	// stdOut (str2);

	const char str3 [11] = "ASDF";
	stdOut (str3);                            // print ASDF
	std::cout << strlen (str3) << std::endl;  // print 4, no matter that array has 11 elements

	// to work need add L (L means white characters)
	const wchar_t* str4 = L"ASDF";  // two bytes per character
	// std::cout << str4 << std::endl; //cant
	std::wcout << str4 << std::endl;  // print ASDF

	// to work need add u(lower case)
	const char16_t* str5 = u"ASDFGHJKL";  // dont know how to print, c++11
	// to work need add U(upper case)
	const char32_t* str6 = U"ASDFGHJKL";  // dont know how to print c++11

	stdOut ("\n\n bytes of types: \n");
	// char is one byte per character
	stdOut ("sizeof (char) " + std::to_string (sizeof (char)));  // char
	// 8 bytes
	stdOut ("sizeof (wchar_t) " + std::to_string (sizeof (wchar_t)));  // char // in windows has 2 bytes? to check
	// 8 bytes
	stdOut ("sizeof (char16_t) " + std::to_string (sizeof (char16_t)));  // char16_t
	// 8 bytes
	stdOut ("sizeof (char32_t) " + std::to_string (sizeof (char32_t)));  // char32_t
	stdOut ("\n\n bytes of consts: \n");
	// 8 bytes
	stdOut ("sizeof (char) " + std::to_string (sizeof (str)));  // char
	// 8 bytes
	stdOut ("sizeof (wchar_t) " + std::to_string (sizeof (str4)));  // char
	// 8 bytes
	stdOut ("sizeof (char16_t) " + std::to_string (sizeof (str5)));  // char16_t
	// 8 bytes
	stdOut ("sizeof (char32_t) " + std::to_string (sizeof (str6)));  // char32_t

	// C++14 we can use std::string_literals

	// std::string str7 = "Hello" + "World"; dont work
	std::string str7 = std::string ("Hello") + "World";  // work
	using namespace std::string_literals;
	std::string str8 = "Hello"s + "World";  // work, without "using namespace std::string_literals;"" dont work

	const char* str9 = R"(some 1
	some 2
	some 3)";  // R(Raw String) ignores escapes char // to work must be in braket ( ) use to make string from some
			   // nested chars, in this example dont need put \n
	stdOut (str9);
	// or
	const char* str10 = R"(<a href="file">C:\Program Files\</a>)";
	stdOut (str10);
};
