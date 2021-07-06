#ifndef RAII_H
#define RAII_H

class Raii
{
   private:
	int* m_SomeVal;

   public:
	explicit Raii (const int& Val);
	~Raii( );
};

Raii::Raii (const int& Val)
{
	m_SomeVal = new int (Val);
}

Raii::~Raii( ) { 
    delete m_SomeVal; 
}

#endif  // RAII_H