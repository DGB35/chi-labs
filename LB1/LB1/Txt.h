#pragma once

namespace l1
{
	class Txt
	{
	public:
		Txt();

		Txt(const Txt &);
		Txt(Txt&&) noexcept;

		Txt& operator=(const Txt&);
		Txt& operator=(Txt&&) noexcept;

		Txt(const char*);

		size_t size() const { return stringCount; };
		void printText();

		~Txt();

	private:
		char** text;
		size_t stringCount;
	};
}


