#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class	Array
{
	public:
		Array() : _size(0), _arr(new int[_size])
		{}
		Array(unsigned int size) : _size(size), 
		Array(const Array& other);

		Array& operator=(const Array& other);
		//T& operator[](unsigned int index);
		~Array()
		{
			if (this->_arr)
				delete[] this->_arr;
		}
	private:
		T*				_arr;
		unsigned int	_size;
};

#endif
