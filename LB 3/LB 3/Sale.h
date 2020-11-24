#pragma once
#include "IProduct.h"
#include "Product.h"
#include "TaxableProduct.h"
#include <vector>
namespace sict
{
	class Sale
	{
	public:
		Sale(const char*);
		void display(std::ostream& os) const;
		~Sale();
	private:
		std::vector<IProduct*> products;
	};
}
