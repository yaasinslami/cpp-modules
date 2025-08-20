#include "Character.hpp"

Character::Character( void ) : _name("default")
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
		_name = other._name;

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

	TrashNode *current = this->_trashHead;
	while (current)
	{
		TrashNode *next = current->next;
		delete current->materia;
		delete current;
		current = next;
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
	std::cout << "Bag is full, storing " << m->getType() << " in trash" << std::endl;
	if (!this->isInBag(m))
		delete m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_bag[idx])
	{
		addToTrash(this->_bag[idx]);
		this->_bag[idx] = NULL;
		std::cout << "Materia " << this->_bag[idx]->getType() << " unequiped from " << this->getName() << "'s inventory at index " << idx << std::endl;
	}
	else if (idx < 0 || idx >= 4)
		std::cout << "Invalid Index " << idx << std::endl;
	else
		std::cout << "The slot " << idx << " is empty" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_bag[idx])
		this->_bag[idx]->use(target);
	else if (idx < 0 || idx >= 4)
		std::cout << "Invalid Index " << idx << std::endl;
	else
		std::cout << "The slot " << idx << " is empty" << std::endl;
}

void	Character::addToTrash(AMateria* m)
{
	TrashNode*	node = new TrashNode(m, this->_trashHead);
	this->_trashHead = node;
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
