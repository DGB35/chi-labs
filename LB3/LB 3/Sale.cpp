#include "Sale.h"
#include <fstream>
#include <iomanip>

extern int FW;

namespace sict
{
	Sale::Sale(const char* fileName)
	{
		std::ifstream is(fileName);
		if (!is.is_open())
			throw std::exception("File not open");
		TaxableProduct p(0, 0, "");
		while(!is.eof())
			products.push_back(p.readRecord(is));
	}

	void Sale::display(std::ostream& os) const
	{
		double totalPrice = 0;
		os << std::setw(FW) << "Product No" 
		   << std::setw(FW) << "Cost" << " " 
	       << std::setw(FW) << std::left << "Taxable" << std::right << std::endl;
		for (auto p : products)
		{
			p->display(os);
			totalPrice += p->price();
		}
		os << std::setw(FW) << "Total price" << std::setw(FW) << totalPrice << std::endl;
	}

	Sale::~Sale()
	{
		for (auto p : products)
			delete p;
	}
}