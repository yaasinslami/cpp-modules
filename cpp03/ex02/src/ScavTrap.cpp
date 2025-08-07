#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->guardMode = false;
	std::cout << "ScavTrap Default Constractor Called"  << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constractor Called"  << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->guardMode = false;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	this->guardMode = other.guardMode;
	std::cout << "ScavTrap Copy Constractor Called"  << std::endl;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap Destructor Called" << std::endl; }

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		this->guardMode = other.guardMode;
		std::cout << "ScavTrap Assignment Operator Called" << std::endl;
	}
	return *this;
}

void	ScavTrap::guardGate( void )
{
	if (!this->guardMode)
	{
		std::cout << this->_name << " set to [Gate keeper] mode now" << std::endl;
		this->guardMode = true;
	}
	else
		std::cout << this->_name << " is already in [Gate keeper] mode" << std::endl;
}
