#include "Dog.hpp"

Dog::Dog() :  Animal("Dog"), _name("defaultDogName")
{
	std::cout << Animal::getType() << " [" << this->getName() << "] called his Default constructor." << std::endl;
}

Dog::Dog(const std::string& name) : Animal("Dog"), _name(name)
{
	std::cout <<  Animal::getType() << " [" << this->getName() <<  "] Parameterized Constructor called"
	 			<< std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	this->_name = other._name;
	std::cout << Animal::getType() << " [" << other.getName() << "] Copy constractor Called"
				<< std::endl;
}

Dog::~Dog()
{
	std::cout << Animal::getType() << " [" << this->getName() << "] Destractor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << Animal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
	Animal::operator=(other);
	this->_name = other._name;
	return *this;
}

std::string const	&Dog::getName(void) const
{
	return this->_name;
}

void Dog::makeSound(void) const
{
	std::cout << Animal::getType() << " [" << this->getName() << "] barks!" << std::endl;
}
