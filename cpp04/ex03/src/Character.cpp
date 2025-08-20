#include "Character.hpp"

Character::Character( void ) : _name("defaultName")
{
	for (int i = 0; i < 4; i++)
		this->_bag[i] = NULL;
	std::cout << "Character object created with default constructor" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_bag[i] = NULL;
	std::cout << "Character " << _name << " created" << std::endl;
}

Character::Character(const Character &other) : _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._bag[i])
			this->_bag[i] = other._bag[i]->clone();
		else
			this->_bag[i] = NULL;
	}
	std::cout << "Character copied" << std::endl;
}

Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			if (this->_bag[i])
				delete this->_bag[i];

			if (other._bag[i])
				this->_bag[i] = other._bag[i]->clone();
			else
				this->_bag[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_bag[i])
			delete this->_bag[i];
	}
	std::cout << "Character " << _name << " destroyed" << std::endl;
}

std::string const &Character::getName( void ) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot equip invalid materia" << std::endl;
		return;
	}

	// check if the materia already in the bag
	if (this->isInBag(m))
	{
		std::cout << "Materia " << m->getType()
				  << " is already equipped" << std::endl;
		return;
	}

	// find an empty slot to store the materia
	for (int i = 0; i < 4; i++)
	{
		if (this->_bag[i] == NULL)
		{
			this->_bag[i] = m;
			std::cout << "Materia " << this->_bag[i]->getType() << " equipped to " << this->_name << "'s inventory at index " << i << std::endl;
			return;
		}
	}
	std::cout << "Bag is full, " << m->getType() << " cant be equiped" << std::endl;
	// if (!this->isInBag(m))
	// 	delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_bag[idx])
	{
		std::cout << "Materia " << this->_bag[idx]->getType() << " unequiped from " << this->getName() << "'s inventory at index " << idx << std::endl;
		this->_bag[idx] = NULL;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Invalid unequip: Index must be in range [0-3]!" << std::endl;
	else
		std::cout << "Invalid unequip: The slot " << idx << " is empty!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this == &target)
	{
		std::cout << "Invalid Use: " << this->getName() << " cant attack himself!" << std::endl;
		return ;
	}
	if (idx >= 0 && idx < 4 && this->_bag[idx])
		this->_bag[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << "Invalid Use: Index must be in range [0-3]!" << std::endl;
	else
		std::cout << "Invalid Use: The slot " << idx << " is empty!" << std::endl;
}

bool	Character::isInBag(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (m && this->_bag[i] == m)
			return true;
	}
	return false;
}
