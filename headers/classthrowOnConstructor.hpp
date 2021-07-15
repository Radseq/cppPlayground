#ifndef CLASSTHROWONCONSTRUCTOR_H
#define CLASSTHROWONCONSTRUCTOR_H

#include <stdexcept>

class classthrowOnConstructor
{
   private:
	/* data */
   public:
	classthrowOnConstructor (const bool& callException);
	~classthrowOnConstructor( );
};

classthrowOnConstructor::classthrowOnConstructor (const bool& callException)
{
	if (callException) throw std::runtime_error ("error");
}

classthrowOnConstructor::~classthrowOnConstructor( ) { }

#endif  // CLASSTHROWONCONSTRUCTOR_H