#include <map>

template<typename T, T undefValue>
class Matrix
{
	using FullIndex = std::pair<unsigned int, unsigned int>;

	std::map<FullIndex, T> _values;
	T _undefValue;
	FullIndex _lastUsedIndex;

public:
	Matrix();
	unsigned Size();
	//Matrix& operator() (unsigned int row, unsigned int col);
	Matrix<T, undefValue>& operator() (unsigned int row, unsigned int col);
	Matrix<T, undefValue>& operator= (const T newValue);
	operator T();	// Introduced for Matrix<T, undefValue>& operator= (const T newValue); call

	auto begin() { return std::begin(_values); }
	auto end() { return std::end(_values); }
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
Matrix<T, undefValue>& Matrix<T, undefValue>::operator()(unsigned int row, unsigned int col)
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


