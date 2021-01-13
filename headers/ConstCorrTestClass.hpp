#ifndef CONST_CORRECTNESS_TEST_CLASS_HPP
#define CONST_CORRECTNESS_TEST_CLASS_HPP

class ConstCorrTestClass
{
	int id {0};
	int mutable method2UsedTimes {0};
	int testModifyVal {0};

   public:
	const int& GetId( )
	{
		++testModifyVal;
		return id;
	};  // const meand return const id

	// const after function means this function will not modify anythink in this class
	// only mutable value can be changet
	const int& GetId2( ) const
	{
		++method2UsedTimes;  // only mutabled can be change by const methods
		return id;
	};

	const int& GetMutabledValue( ) const { return method2UsedTimes; };

	void SetId (const int& newId) { id = newId; };
};

#endif  // CONST_CORRECTNESS_TEST_CLASS_HPP