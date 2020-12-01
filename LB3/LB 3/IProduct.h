#pragma once
#include <ostream>

namespace sict
{
	class IProduct
	{
	public:
		virtual double price() const = 0;
		virtual void display(std::ostream&) const = 0;
		virtual IProduct* readRecord(std::ifstream&) = 0;

		friend std::ostream& operator << (std::ostream&, const IProduct&);

		virtual ~IProduct() {};
	protected:
		size_t _id;
		double _price;
	};
}
