#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>

#include "Txt.h"
#define TIMEP(start, end) (std::chrono::duration_cast<std::chrono::nanoseconds>((end) - (begin)).count())

int main(int argc, char* argv[])
{
	std::ofstream ofs("Lab1Output.txt");

	if (argc == 1)
	{
		std::cout << argv[0] << ": missing file \n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cout << argv[0] << ": too many arg\n";
		return 2;
	}


	auto begin = std::chrono::high_resolution_clock::now();
	auto end = std::chrono::high_resolution_clock::now();

	{
		begin = std::chrono::high_resolution_clock::now();
		l1::Txt a;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Def Const "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		l1::Txt b(argv[1]);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Cust Const  "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - b.size = " << b.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		a = b;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Cp Assig     "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		a = std::move(b);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Mv Assig     "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - a.size = " << a.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		l1::Txt c = a;
		end = std::chrono::high_resolution_clock::now();
		ofs << "Cp Const    "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - c.size = " << c.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
		l1::Txt d = std::move(a);
		end = std::chrono::high_resolution_clock::now();
		ofs << "Mv Const    "
			<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
			<< " - d.size = " << d.size() << std::endl;

		begin = std::chrono::high_resolution_clock::now();
	}
	end = std::chrono::high_resolution_clock::now();
	ofs << "Dest          "
		<< std::setw(9) << TIMEP(begin, end) << " nanoseconds"
		<< std::endl;

	ofs.close();
	return 0;
}