#pragma once
#include <ostream>
#include "IProduct.h"

namespace sict 
{
	class Product : public IProduct
	{
	public:
		Product(size_t id, double price);
		double price() const override { return _price; }
		void display(std::ostream&) const override;
		IProduct* readRecord(std::ifstream&) override;

		friend std::ostream& operator << (std::ostream&, const IProduct&);
	};
}


