#include "ScalarConverter.hpp"
#include <>
#include <cstdlib>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
  (void)other;
  return *this;
}

static bool isDouble(const std::string &literal) {
  char *endptr;
  std::strtod(literal.c_str(), &endptr);

  // If endptr points to the end of the string, the whole string was parsed as a
  // double Also, make sure the string does not end with 'f'
  return *endptr == '\0' && (literal.find('f') == std::string::npos);
}

static bool isFloat(const std::string &literal) {
  if (literal.size() < 2 || literal[literal.size() - 1] != 'f')
    return false;

  std::string digitPart = literal.substr(0, literal.size() - 1);
  char *endptr;
  std::strtod(digitPart.c_str(), &endptr);

  return *endptr == '\0';
}

static bool isInt(const std::string &literal) {
  char *strl;
  long number = std::strtol(literal.c_str, strl, 10);
  if (*strl == '\0')
    return true;
  if (number >= INT_MAX)
}

void ScalarConverter::convert(const std::string &literal) {}
