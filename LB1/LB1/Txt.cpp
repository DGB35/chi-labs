#include "Txt.h"

#include <iostream>
#include <fstream>

namespace l1
{
	Txt::Txt() : text{ nullptr }, stringCount{ 0 }
	{
	}


	Txt::Txt(const Txt& obj) : stringCount(obj.stringCount)
	{
		char** text_clone = new char* [obj.stringCount];
		for (size_t i = 0; i < obj.stringCount; ++i)
		{
			text_clone[i] = new char[strlen(obj.text[i]) + 1];
			strcpy_s(text_clone[i], strlen(obj.text[i]) + 1, obj.text[i]);
		}
		text = text_clone;
	}


	Txt::Txt(Txt&& obj) noexcept
	{
		std::swap(text, obj.text);
		std::swap(stringCount, obj.stringCount);
	}


	Txt::Txt(const char* fileName) : Txt()
	{

		std::ifstream in(fileName);

		if (!in.is_open())
			std::cout << "File read error";

		while (in.ignore((std::numeric_limits<std::streamsize>::max)(), '\n'))
			stringCount++;

		//Setting the file pointer to the beginning
		in.clear();
		in.seekg(0, std::ios::beg);


		text = new char* [stringCount];

		char* temp = new char[1024];
		for (size_t i = 0; i < stringCount; ++i)
		{
			in.getline(temp, 1024, '\n');
			text[i] = new char[strlen(temp) + 1];
			strcpy_s(text[i], strlen(temp) + 1, temp);
		}
		delete[] temp;
	}


	Txt& l1::Txt::operator=(const Txt& obj)
	{
		if (this != &obj)
		{
			char** text_clone = new char* [obj.stringCount];
			for (size_t i = 0; i < obj.stringCount; ++i)
			{
				text_clone[i] = new char[strlen(obj.text[i]) + 1];
				strcpy_s(text_clone[i], strlen(obj.text[i]) + 1, obj.text[i]);
			}

			for (size_t i = 0; i < stringCount; ++i)
			{
				delete[] text[i];
			}
			delete[] text;

			text = text_clone;
			stringCount = obj.stringCount;
		}
		return *this;
	}


	Txt& Txt::operator=(Txt&& obj) noexcept
	{
		if (this != &obj)
		{
			std::swap(text, obj.text);
			std::swap(stringCount, obj.stringCount);
		}
		return *this;
	}


	void Txt::printText()
	{
		for (int i = 0; i < stringCount; ++i)
		{
			std::cout << text[i] << '\n';
		}
	}


	Txt::~Txt()
	{
		for (size_t i = 0; i < stringCount; ++i)
		{
			delete[] text[i];
		}
		delete[] text;
	}

}