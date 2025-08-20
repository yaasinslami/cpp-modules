#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _materias()
{
	std::cout << "Materia source created with default constractor" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) : _materias()
{
	for (int i = 0; i < 4; i++)
	{
		if (other._materias[i])
			this->_materias[i] = other._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	std::cout << "MateriaSource copied" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materias[i])
				delete this->_materias[i];
			if (other._materias[i])
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
		std::cout << "MateriaSource assigned" << std::endl;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid Materia" << std::endl;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = m->clone();
			std::cout << "Materia " << m->getType() << " learned in slot " << i << std::endl;
			delete m;
			return;
		}
	}

	std::cout << "Materia " << m->getType() << " can't be added, materias bag is full" << std::endl;
	delete m;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
			return this->_materias[i]->clone();
	}
	std::cout << "Materia " << type << " not found!" << std::endl;
	return (0);
}
