#pragma once

template <typename A, typename B>
class Pair
{
public:
	Pair();
	Pair(const A&, const B&);
	const A& getKey() const;
	const B& getValue() const;
private:
	A key;
	B value;
};

template<typename A, typename B>
inline Pair<A, B>::Pair() : key(A()), value(B())
{
}

template<typename A, typename B>
inline Pair<A, B>::Pair(const A& a, const B& b) : Pair()
{
	key = a;
	value = b;
}

template<typename A, typename B>
inline const A& Pair<A, B>::getKey() const
{
	return key;
}

template<typename A, typename B>
inline const B& Pair<A, B>::getValue() const
{
	return value;
}
