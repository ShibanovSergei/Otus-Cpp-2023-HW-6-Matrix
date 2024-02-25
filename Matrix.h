#include <map>
#include <tuple>

template<typename T, T undefValue>
class Matrix
{
	using FullIndex = std::pair<int, int>;
	std::map<FullIndex, T> _values;
	T _undefValue;
	FullIndex _lastUsedIndex;

	struct Iterator
	{
		using ResultType = std::tuple<const int&, const int&, T&>;

	public:
		Iterator(std::map<FullIndex, T>* values) { _values = values; };

		Iterator operator++() { ++iter; return *this; }
		bool operator!=(const Iterator& other) { return iter != other.iter; }
		ResultType operator*() { return iteratorToTuple(iter); }
		Iterator begin() { iter = _values->begin(); return *this; };
		Iterator end() { iter = _values->end(); return *this; };

	private:
		std::map<FullIndex, T>::iterator iter;
		std::map<FullIndex, T>* _values;
		ResultType iteratorToTuple(std::map<FullIndex, T>::iterator it)
		{
			return std::tie(iter->first.first, iter->first.second, iter->second);
		}
		
	} iterator{ &_values };

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

