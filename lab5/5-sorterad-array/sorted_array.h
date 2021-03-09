#ifndef SORTED_ARRAY_H
#define SORTED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <ostream>

/* Kompletteringar

* Sorted_Array ska ha 1 mallifierad komparator istället för 2 hårdspecifierade
* flip ska inte användas för att välja komparator, insert ska automatiskt kunna veta vilken 
	komparator som körs pga ovanstående.
* Sorted_Array ska ta in komparatortypen som en mallparameter
* Sorted_Array ska ha ett default värde för komparatorns mallparameter och konstruktor värde.
* Vi vet inte hur stort T kan vara och ska därför aldrig tas som kopia om det inte måste.

*/

template <typename T>
class Less
{
public:
	Less() = default;
	bool compare(const T &a, const T &b);
};

template <typename T>
class Distance
{
public:
	Distance() = default;
	Distance(T c) : center{c} {}
	bool compare(const T &a, const T &b);

private:
	T center{};
};

template <typename T, class K = Less<T>>
class sorted_array
{
public:
	sorted_array() = default;
	sorted_array(std::initializer_list<T> list);
	sorted_array(std::initializer_list<T> list, K new_comparator);
	
	void insert(T value);
	T erase(int index);

	T &operator[](int index);
	T operator[](int index) const;

	T &at(int index);
	T at(int index) const;

	int size() const;

private:
	K comparator{};
	std::vector<T> data{};
};

template <typename T, class K = Less<T>>
std::ostream &operator<<(std::ostream &os, sorted_array<T, K> const &array);

#include "sorted_array.cc"
#endif //SORTED_ARRAY_H
