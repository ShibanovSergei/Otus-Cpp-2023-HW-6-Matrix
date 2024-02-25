#include <map>
#include <tuple>

using FullIndex = std::pair<int, int>;

template<typename T>
struct MatrixIterator
{
	// using DataType = std::tuple<int&, int&, T&>;
public:	
	MatrixIterator(std::map<FullIndex, T>* values)
	{
		a_values = values;
	};
	void SetData(std::map<FullIndex, T> &values) 
	{ 
		a_values = values; 
		a_values[std::make_pair(5, 5)] = 25;
	}

	MatrixIterator operator++() { ++iter; return *this; }
	bool operator!=(const MatrixIterator& other) { return iter != other.iter; }
	std::tuple<const int&, const int&, T&> operator*() { return iteratorToTuple(iter); }
	MatrixIterator begin() 
	{ 
		iter = a_values->begin(); return *this; 
	};
	MatrixIterator end() { iter = a_values->end(); return *this; };
private:
	std::map<FullIndex, T> *a_values;
	std::tuple<const int&, const int&, T&> iteratorToTuple(std::map<FullIndex, T>::iterator it)
	{
		auto res = std::tie(iter->first.first, iter->first.second, iter->second);
		return res;
	}
	std::map<FullIndex, T>::iterator iter;
};


template<typename T, T undefValue>
class Matrix
{
	std::map<FullIndex, T> _values;
	T _undefValue;
	FullIndex _lastUsedIndex;
	MatrixIterator<T> iterator { &_values };

public:
	Matrix();
	unsigned Size();
	Matrix<T, undefValue>& operator() (int row, int col);
	Matrix<T, undefValue>& operator= (const T newValue);
	operator T();	// Introduced for Matrix<T, undefValue>& operator= (const T newValue); call

	auto begin() { return iterator.begin(); }
	auto end() { return iterator.end(); }
};

template<typename T, T undefValue>
inline Matrix<T, undefValue>::Matrix()
{
	_undefValue = undefValue;
}

template<typename T, T undefValue>
inline unsigned Matrix<T, undefValue>::Size()
{
	return _values.size();
}

template<typename T, T undefValue>
Matrix<T, undefValue>& Matrix<T, undefValue>::operator()(int row, int col)
{
	_lastUsedIndex = std::make_pair(row, col);
	return *this;
}

template<typename T, T undefValue>
inline Matrix<T, undefValue>& Matrix<T, undefValue>::operator=(const T newValue)
{
	if (newValue == _undefValue)
	{
		if (_values.contains(_lastUsedIndex))
		{
			_values.erase(_lastUsedIndex);
		}
	}
	else	
		_values[_lastUsedIndex] = newValue;
	
	return *this;
}

template<typename T, T undefValue>
inline Matrix<T, undefValue>::operator T()
{
	if (_values.contains(_lastUsedIndex))
		return _values[_lastUsedIndex];
	else
		return _undefValue;
}

