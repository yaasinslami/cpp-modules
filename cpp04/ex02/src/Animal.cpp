#include "Animal.hpp"

Animal::Animal( void ) : type("default_animal")
{
	std::cout << this->type << " Constractor Called" << std::endl;
}

Animal::Animal(const std::string& _type) : type(_type)
{
	std::cout << "Animal " << this->getType() << " Created" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal Copy Constructor called from " << other.type << std::endl;
	this->type = other.type;
}

Animal::~Animal()
{
	std::cout << "Animal [" << this->type << "] Destractor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "Animal Assignment Operator called for [" << this->type  << "] Type" << std::endl;
	}
	return *this;
}

std::string const	&Animal::getType(void) const
{
	return this->type;
}
