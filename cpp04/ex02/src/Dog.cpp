#include "Dog.hpp"

Dog::Dog() :  Animal("Dog"), _name("defaultDogName"), _brain(new Brain("Dog"))
{
	std::cout << Animal::getType() << " [" << this->getName() << "] called his Default constructor." << std::endl;
}

Dog::Dog(const std::string& name) : Animal("Dog"), _name(name), _brain(new Brain("Dog"))
{
	std::cout <<  Animal::getType() << " [" << this->getName() <<  "] Parameterized Constructor called"
	 			<< std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _name(other._name)
{
	this->_brain = new Brain(*other._brain);
	std::cout << Animal::getType() << " Copy constractor Called"
				<< std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << Animal::getType() << " [" << this->getName() << "] Destractor Called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		this->_name = other._name;

		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		std::cout << Animal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
	}
	return *this;
}

std::string const	&Dog::getName(void) const
{
	return this->_name;
}

void	Dog::setName(const std::string& name)
{
	this->_name = name;
}

Brain&	Dog::getBrain(void ) const
{
	return (*this->_brain);
}

void Dog::makeSound(void) const
{
	std::cout << Animal::getType() << " [" << this->getName() << "] barks!" << std::endl;
}

void Dog::logIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "[Dog::logIdea] Invalid index (" << idx
				  << ")! Valid range is [0..99]." << std::endl;
		return;
	}
	std::cout << "-> Brain owner: " << this->getBrain().getOwner()
			  << " [" << this->getName() << "], idea[" << idx << "]: "
			  << this->getBrain().getIdea(idx) << std::endl;
}
