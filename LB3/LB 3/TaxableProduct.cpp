#include "TaxableProduct.h"
#include <iomanip>
#include <fstream>
#include <sstream>

extern int FW;

namespace sict 
{
	std::unordered_map<std::string, double> TaxableProduct::Taxes { {"H", 0.13}, {"P", 0.08} };

	TaxableProduct::TaxableProduct(size_t id, double price, std::string taxStatus) : Product(id, price), _taxStatus(taxStatus)
	{
	}

	double TaxableProduct::price() const
	{
		auto taxSearch = Taxes.find(_taxStatus);
		if (taxSearch != Taxes.end())
			return _price * (*taxSearch).second;
		else 
			return _price;
	}

	void TaxableProduct::display(std::ostream& os) const
	{
		os << std::fixed << std::setprecision(2) << std::setw(FW) << _id << std::setw(FW) << price();
		auto taxSearch = Taxes.find(_taxStatus);
		if (taxSearch != Taxes.end())
			os << " " << std::setw(FW) << std::left << (*taxSearch).first + "ST" << std::right;
		os << std::endl;
	}

	IProduct* TaxableProduct::readRecord(std::ifstream& is)
	{
		std::string line, taxStatus;
		std::istringstream iss;
		getline(is, line);
		iss.str(line);
		iss >> _id >> _price >> taxStatus;
		if (taxStatus == "")
			return new Product(_id, _price);
		else
			return new TaxableProduct(_id, _price, taxStatus);
	}
	
	std::ostream& operator<<(std::ostream& os, const IProduct& p)
	{
		p.display(os);
		return os;
	}
}

