#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	*datap = new Data(12, "Clarence");

	std::cout << "\n======= Before Casting ======" << std::endl;
	std::cout <<  "datap adresse: " << datap << std::endl;
	std::cout << *datap << std::endl;

	uintptr_t	raw = Serializer::serialize(datap);

	std::cout << "raw = " << raw << std::endl;

	Data* datap_ = Serializer::deserialize(raw);

	std::cout << "\n======= After Casting ======" << std::endl;
	std::cout <<  "datap_ adresse: " << datap_ << std::endl;

	std::cout << *datap_ << std::endl;
}
