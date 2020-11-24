#pragma once
#include "Product.h"
#include <unordered_map>
namespace sict
{
	class TaxableProduct : public Product
	{
	public:
		TaxableProduct(size_t, double, std::string);
		double price() const override;
		void display(std::ostream& os) const override;
		IProduct* readRecord(std::ifstream&) override;

		friend std::ostream& operator << (std::ostream&, const IProduct&);
	protected:
		enum class Tax { H, P, N };
		static std::unordered_map<std::string, double> Taxes;
		std::string _taxStatus;
	};
}
