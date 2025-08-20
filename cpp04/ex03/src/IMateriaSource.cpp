#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
	std::cout << "IMateriaSource object created with default constructor" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &other)
{
	*this = other;
	std::cout << "IMateriaSource object copied" << std::endl;
}

IMateriaSource	&IMateriaSource::operator=(IMateriaSource const &other)
{
	(void)other;
	std::cout << "IMateriaSource Assignment Operator Called!" << std::endl;
	return (*this);
}

IMateriaSource::~IMateriaSource()
{
	std::cout << "IMateriaSource Destructor called" << std::endl;
}
