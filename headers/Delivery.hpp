#ifndef DELIVERY_CLASS_HPP
#define DELIVERY_CLASS_HPP

#include "BaseDelivery.hpp"

class Delivery : public BaseDelivery
{
	int a {0};

   public:
	void       add (const int&& val) override;
	const int& getVal( ) override;
	void       setVal (const int&& val) { a = val; };
};

#endif  // DELIVERY_CLASS_HPP
