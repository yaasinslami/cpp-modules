#include "Brain.hpp"

Brain::Brain() : _owner("default_animal")
{
	for (int i = 0; i < IDEAS_NB; ++i)
			_ideas[i] = "DEFAULT_IDEA";
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const std::string& owner) : _owner(owner)
{
	for (int i = 0; i < IDEAS_NB; ++i)
			_ideas[i] = " DEFAULT_IDEA";
	std::cout << this->getOwner() << " Brain constructored" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		this->setOwner(other.getOwner());
		for (int i = 0; i < IDEAS_NB; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < IDEAS_NB)
		_ideas[index] = idea;
}

const std::string&	Brain::getIdea(int index) const
{
	static const std::string empty = "";
	if (index >= 0 && index < IDEAS_NB)
		return _ideas[index];
	return empty;
}

const std::string& Brain::getOwner() const
{
	return (this->_owner);
}

void	Brain::setOwner(const std::string& owner)
{
	this->_owner = owner;
}
