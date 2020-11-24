#include "Product.h"
#include <iomanip>
#include <fstream>
#include <sstream>

extern int FW;

namespace sict
{
	Product::Product(size_t id, double price)
	{
		_id = id;
		_price = price;
	}

	void Product::display(std::ostream& os) const
	{
		os << std::fixed << std::setprecision(2) << std::setw(FW) << _id << std::setw(FW) << _price << std::endl;
	}

	IProduct* Product::readRecord(std::ifstream& is)
	{
		std::string line;
		std::istringstream iss;
		getline(is, line);
		iss.str(line);
		iss >> _id >> _price;
		return new Product(_id, _price);
	}

	std::ostream& operator<<(std::ostream& os, const IProduct& p)
	{
		p.display(os);
		return os;
	}
}