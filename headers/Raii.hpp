#ifndef RAII_H
#define RAII_H

class Raii
{
   private:
	int* m_SomeVal;

   public:
	explicit Raii (const int& Val) noexcept; // explicit to no allow do smt. like Raii raiiObj = 10;
	~Raii( ) noexcept;

	// copy constructor
	Raii (const Raii& other) = delete;
	// copy assignment
	Raii& operator= (const Raii& other) = delete;

	// move constructor
	Raii (Raii&& other) noexcept
	{
		std::cout << "move constructor"
				  << "\n";
		if (this != &other && other.m_SomeVal != nullptr)
		{
			m_SomeVal       = other.m_SomeVal;
			other.m_SomeVal = nullptr;
		}
	}

	// move assignment
	Raii& operator= (Raii&& other) noexcept
	{
		std::cout << "move assignment"
				  << "\n";
		if (this != &other && other.m_SomeVal != nullptr)
		{
			delete m_SomeVal;  // prevent memory leak
			// rest below is same as move operator
			m_SomeVal       = other.m_SomeVal;
			other.m_SomeVal = nullptr;
		}

		return (*this);
	}
};

Raii::Raii (const int& Val) noexcept { m_SomeVal = new int (Val); }

Raii::~Raii( ) noexcept { delete m_SomeVal; }

#endif  // RAII_H