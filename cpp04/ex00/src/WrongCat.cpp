#include "WrongCat.hpp"

WrongCat::WrongCat() :  WrongAnimal("WrongCat"), _name("defaultWrongCatName")
{
	std::cout << WrongAnimal::getType() << " [" << this->getName() << "] called his Default constructor." << std::endl;
}

WrongCat::WrongCat(const std::string& name) : WrongAnimal("WrongCat"), _name(name)
{
	std::cout <<  WrongAnimal::getType() << " [" << this->getName() <<  "] Parameterized Constructor called"
	 			<< std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	this->_name = other._name;
	std::cout << WrongAnimal::getType() << " [" << other.getName() << "] Copy constractor Called"
				<< std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << WrongAnimal::getType() << " [" << this->getName() << "] Destractor Called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << WrongAnimal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
	WrongAnimal::operator=(other);
	this->_name = other._name;
	return *this;
}

std::string const	&WrongCat::getName(void) const
{
	return this->_name;
}

void WrongCat::makeSound(void) const
{
	std::cout << WrongAnimal::getType() << " [" << this->getName() << "] meows!" << std::endl;
}
