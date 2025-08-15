#include "../inc/Cat.hpp"

Cat::Cat() :  Animal("Cat"), _name("defaultCatName"), _brain(new Brain("Cat"))
{
	std::cout << Animal::getType() << " [" << this->getName() << "] called his Default constructor." << std::endl;
}

Cat::Cat(const std::string& name) : Animal("Cat"), _name(name), _brain(new Brain("Cat"))
{
	std::cout <<  Animal::getType() << " [" << this->getName() <<  "] Parameterized Constructor called"
	 			<< std::endl;
}

Cat::Cat(const Cat& other) : Animal(other), _name(other._name)
{
	this->_brain = new Brain(*other._brain);
	std::cout << Animal::getType() << " [" << other.getName() << "] Copy constractor Called"
				<< std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << Animal::getType() << " [" << this->getName() << "] Destractor Called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		std::cout << Animal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
		Animal::operator=(other);
		this->_name = other._name;

		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

std::string const	&Cat::getName(void) const
{
	return this->_name;
}

Brain&	Cat::getBrain(void ) const
{
	return (*this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << Animal::getType() << " [" << this->getName() << "] meows!" << std::endl;
}
