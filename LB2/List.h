#pragma once

template <typename T, size_t N>
class List
{
public:
	List();

	size_t size() const { return listSize; }

	const T& operator [] (size_t index) const;
	void operator += (const T&);

private:
	T list[N];
	size_t listSize;
};

template<typename T, size_t N>
inline List<T, N>::List() : listSize { 0 }
{
}

template<typename T, size_t N>
inline const T& List<T, N>::operator[](size_t index) const
{
	if (index >= N) throw std::out_of_range("Out of range");
	return list[index];
}

template<typename T, size_t N>
inline void List<T, N>::operator+=(const T& element)
{
	if (listSize < N)
	{
		list[listSize] = element;
		++listSize;
	}
}
