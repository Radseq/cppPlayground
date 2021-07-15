#ifndef RAII_H
#define RAII_H

class Raii
{
   private:
	int* m_SomeVal;

   public:
	explicit Raii (const int& Val) noexcept;
	~Raii( ) noexcept;

	// copy constructor
	Raii (const Raii& other) = delete;
	// copy assignment
	Raii& operator= (const Raii& other) = delete;

	// move constructor
	Raii (Raii&& other) noexcept
	{
		// to test
		*m_SomeVal = *other.m_SomeVal;
	}

	// move assignment
	Raii& operator= (Raii&& other) noexcept
	{
		// to test
		if (this != &other) { *m_SomeVal = *other.m_SomeVal; }
		return (*this);
	}
};

Raii::Raii (const int& Val) noexcept { m_SomeVal = new int (Val); }

Raii::~Raii( ) noexcept { delete m_SomeVal; }

#endif  // RAII_H