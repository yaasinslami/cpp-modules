#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default Constractor Called"  << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	std::cout << "FragTrap Constractor Called"  << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy Constractor Called"  << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " Destructor Called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "FragTrap Assignment Operator Called" << std::endl;
	}
	return *this;
}

void		FragTrap::highFivesGuys( void ) const
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five! ✋" << std::endl;
}
