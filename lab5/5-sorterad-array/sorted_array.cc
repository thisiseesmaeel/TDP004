#include <utility>
#include <stdexcept>
#include <iostream>

using namespace std;

// ----------------------------------------------------------------------

// LESS

template <typename T>
bool Less<T>::compare(const T & a, const T & b)
{
		return (a < b);
}

// ----------------------------------------------------------------------

// DISTANCE

template <typename T>
bool Distance<T>::compare(const T & a, const T & b)
{
		return (abs(center - a) < abs(center - b));
}

// ----------------------------------------------------------------------

// SORTED_ARRAY

template <typename T, class K>
sorted_array<T, K>::sorted_array(initializer_list<T> list)
    : data{}
{    
    for (T val : list)
    {
        insert(val);
    }
}

template <typename T, class K>
sorted_array<T, K>::sorted_array(initializer_list<T> list, K new_comparator)
    : data{}, comparator{new_comparator}
{    
    for (T val : list)
    {
        insert(val);
    }
}

template <typename T, class K>
void sorted_array<T, K>::insert(T value)
{
    data.push_back(value);
    for (int i {size() - 1}; i > 0; --i)
    {
				if (comparator.compare(data[i], data[i-1]))
		    //if (data[i] < data[i-1])
		    {
		        swap(data[i-1], data[i]);
		    }
		    else
		    {
		        break;
		    }
    }
}

template <typename T, class K>
T sorted_array<T, K>::erase(int index)
{
    if (index < 0 || index >= size())
        throw std::out_of_range{"unable to erase; index is out of bounds."};
    for (int i {index}; i + 1 < size(); ++i)
    {
        swap(data[i], data[i+1]);
    }
    T value {data.back()};
    data.pop_back();
    return value;
}

template <typename T, class K>
T & sorted_array<T, K>::operator[](int index)
{
    return data[index];
}

template <typename T, class K>
T sorted_array<T, K>::operator[](int index) const
{
    return data[index];
}

template <typename T, class K>
T & sorted_array<T, K>::at(int index)
{
    return data.at(index);
}

template <typename T, class K>
T sorted_array<T, K>::at(int index) const
{
    return data.at(index);
}

template <typename T, class K>
int sorted_array<T, K>::size() const
{
    return static_cast<int>(data.size());
}

template <typename T, class K>
ostream & operator<<(ostream & os, sorted_array<T, K> const & array)
{
    if (array.size() == 0)
    {
        os << "{}";
        return os;
    }
    os << '{' << array[0];
    for (int i {1}; i < array.size(); ++i)
    {
        os << ", " << array[i];
    }
    os << '}';
    return os;
}

