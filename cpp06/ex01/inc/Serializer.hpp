#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cstdint>

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer( void );
		~Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
};

#endif
