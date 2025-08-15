#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("default_WrongAnimal")
{
	std::cout << this->type << " Constractor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& _type) : type(_type)
{
	std::cout << "WrongAnimal " << this->getType() << " Created" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Copy Constructor called from " << other.type << std::endl;
	this->type = other.type;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal [" << this->type << "] Destractor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
		std::cout << "WrongAnimal Assignment Operator called for [" << this->type  << "] Type" << std::endl;
	}
	return *this;
}

std::string const	&WrongAnimal::getType(void) const
{
	return this->type;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal [" << this->getType() << "] made a Sound!" << std::endl;
}
