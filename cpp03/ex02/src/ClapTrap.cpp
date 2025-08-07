
#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _name("DEFAULT"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Default Constractor Called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " Enter the game!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap Copy Constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap Destractor Called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		std::cout << "ClapTrap Assignement Operator Called" << std::endl;
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack( const std::string& target )
{
	if (this->_hitPoints && this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << "  attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy or hit points left and can't attack." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints)
		std::cout << "ClapTrap " << this->_name << " takes " << amount <<  " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints < 0)
		this->_hitPoints = 0;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPoints)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself, recovering " << amount << " hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " has no energy or hit points left and can't repair itself." << std::endl;
}

void	ClapTrap::showStatus( void ) const
{
	std::cout << "==== ClapTrap status ====" << std::endl;
	std::cout << "name: " << this->_name << std::endl;
	std::cout << "hitPoints: " << this->_hitPoints << std::endl;
	std::cout << "energyPoints: " << this->_energyPoints << std::endl;
	std::cout << "attackDamage: " << this->_attackDamage << std::endl;
	std::cout << "=========================" << std::endl;
}
