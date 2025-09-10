#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>
#include <iostream>

template <typename T>
class	Array
{
	public:
		Array() : _size(0), _arr(new T[_size]())
		{}
		Array(unsigned int size) : _size(size), _arr(new T[this->_size]())
		{}
		Array(const Array& other) : _size(other._size), _arr(new T[other._size]())
		{
			for (size_t i = 0; i < _size; i++)
				this->_arr[i] = other._arr[i];
		}
		~Array()
		{
			if (this->_arr)
				delete[] this->_arr;
		}
		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				if (this->_arr)
					delete[] this->_arr;
				this->_size = other._size;
				this->_arr = new T[this->_size]();
				for (size_t i = 0; i < _size; i++)
					this->_arr[i] = other._arr[i];
			}
			return (*this);
		}
		T& operator[](size_t index)
		{
			if (index >= this->_size)
				throw Array<T>::InvalidIndexException();
			return (this->_arr[index]);
		}
		const T& operator[](size_t index) const
		{
			if (index >= this->_size)
				throw Array<T>::InvalidIndexException();
			return _arr[index];
		}

		size_t	size( void ) const
		{
			return this->_size;
		}

		class	InvalidIndexException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Error: Invalid Index");
				}
		};

	private:
		size_t			_size;
		T*				_arr;
};

template <typename U>
std::ostream&	operator<<(std::ostream& os, const Array<U>& arr)
{
	os << "[";
	for (size_t i = 0; i < arr.size(); i++)
	{
		os << arr[i];
		if (i + 1 < arr.size())
			os << ", ";
	}
	os << "]";
	return os;
}

#endif
