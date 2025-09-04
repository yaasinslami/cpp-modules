#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return 0;
	}

	ScalarConverter::convert(av[1]);
}
