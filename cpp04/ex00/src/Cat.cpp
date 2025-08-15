#include "Cat.hpp"

Cat::Cat() :  Animal("Cat"), _name("defaultCatName")
{
	std::cout << Animal::getType() << " [" << this->getName() << "] called his Default constructor." << std::endl;
}

Cat::Cat(const std::string& name) : Animal("Cat"), _name(name)
{
	std::cout <<  Animal::getType() << " [" << this->getName() <<  "] Parameterized Constructor called"
	 			<< std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->_name = other._name;
	std::cout << Animal::getType() << " [" << other.getName() << "] Copy constractor Called"
				<< std::endl;
}

Cat::~Cat()
{
	std::cout << Animal::getType() << " [" << this->getName() << "] Destractor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << Animal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
	Animal::operator=(other);
	this->_name = other._name;
	return *this;
}

std::string const	&Cat::getName(void) const
{
	return this->_name;
}

void Cat::makeSound(void) const
{
	std::cout << Animal::getType() << " [" << this->getName() << "] meows!" << std::endl;
}
