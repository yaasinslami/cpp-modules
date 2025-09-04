#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

static bool isDouble(const std::string &literal)
{
	char *endptr;
	std::strtod(literal.c_str(), &endptr);

	return *endptr == '\0';
}

static bool isFloat(const std::string &literal)
{
	if (literal.size() < 2 || literal[literal.size() - 1] != 'f')
		return false;

	std::string digitPart = literal.substr(0, literal.size() - 1);
	char *endptr;
	std::strtod(digitPart.c_str(), &endptr);

	return *endptr == '\0';
}

static bool isInt(const std::string &literal)
{
	char *strl;
	long number = std::strtol(literal.c_str(), &strl, 10);
	if (number > INT_MAX || number < INT_MIN)
		return false;
	if (*strl == '\0')
		return true;
	return false;
}

void ScalarConverter::convert(const std::string &literal)
{
	if (literal.size() == 1 && !std::isdigit(literal[0]))
	{
		char c = literal[0];
		if (!std::isprint(c))
		{
			std::cout << "Invalid input: [char] Non displayable" << std::endl;
			return;
		}
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	if (isInt(literal))
	{
		int n = std::strtol(literal.c_str(), NULL, 10);
		std::cout << "char: ";
		if (std::isprint(n))
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		else if (isnan(n) || isinf(n) || n < 0 || n > 127)
			std::cout << "impossible" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(n) << std::endl;
	}
	else if (isFloat(literal) || isDouble(literal))
	{
		std::string digitPart;
		if (isFloat(literal))
			digitPart = literal.substr(0, literal.size() - 1);
		else
			digitPart = literal;
		errno = 0;
		double f = std::strtod(digitPart.c_str(), NULL);
		if (errno == ERANGE)
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}

		std::cout << "char: ";
		if (std::isprint(static_cast<int>(f)))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else if (isnan(f) || isinf(f) || f < 0 || f > 127)
			std::cout << "impossible" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		if (isnan(f) || isinf(f) || f > INT_MAX || f < INT_MIN)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(f) << std::endl;

		if (isinf(f))
		{
			if (f > 0)
				std::cout << "float: inff" << std::endl;
			else
				std::cout << "float: -inff" << std::endl;
		}
		else if (isnan(f))
			std::cout << "float: nanf" << std::endl;
		else if (f > FLT_MAX || f < -FLT_MAX)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
		std::cout << "double: " << f << std::endl;
	}
	else
		std::cout << "Invalid input!" << std::endl;
}
