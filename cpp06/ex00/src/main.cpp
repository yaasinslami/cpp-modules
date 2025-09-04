#include "../inc/ScalarConverter.hpp"
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


// int	main()
// {
// 	// if (ac != 2)
// 	// {
// 	// 	std::cerr << "Error: Invalid number of arguments." << std::endl;
// 	// 	std::cerr << "Usage: ./convert [literal]" << std::endl;
// 	// 	return 0;
// 	// }

// 	// ScalarConverter::convert(av[1]);
// 	std::cout <<  std::fixed << std::numeric_limits<float>::max() << std::endl;
// }

// int: 2147483647
// float: 3.40282e+38f
// double: 1.79769e+308

/*
340282346638528859811704183484516925440.000000
*/

/*
179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
*/