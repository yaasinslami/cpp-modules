#ifndef	SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <limits>

#define FLT_MAX std::numeric_limits<float>::max()

class ScalarConverter
{
	public:
		static void	convert(const std::string& literal);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
};

#endif