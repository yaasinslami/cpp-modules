#include "Cat.hpp"

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
	std::cout << Animal::getType() << " Copy constractor Called"
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
		Animal::operator=(other);
		this->_name = other._name;

		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		std::cout << Animal::getType() << " Assignment Operator assigns [" << other.getName() << "] to [" << this->getName() << "]" << std::endl;
	}
	return *this;
}

std::string const	&Cat::getName(void) const
{
	return this->_name;
}

void	Cat::setName(const std::string& name)
{
	this->_name = name;
}

Brain&	Cat::getBrain(void ) const
{
	return (*this->_brain);
}

void Cat::makeSound(void) const
{
	std::cout << Animal::getType() << " [" << this->getName() << "] meows!" << std::endl;
}

void Cat::logIdea(int idx) const
{
	if (idx < 0 || idx >= 100)
	{
		std::cout << "[Cat::logIdea] Invalid index (" << idx
				  << ")! Valid range is [0..99]." << std::endl;
		return;
	}
	std::cout << "-> Brain owner: " << this->getBrain().getOwner()
			  << " [" << this->getName() << "], idea[" << idx << "]: "
			  << this->getBrain().getIdea(idx) << std::endl;
}
