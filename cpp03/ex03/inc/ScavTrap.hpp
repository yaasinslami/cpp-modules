#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	private:
		bool	guardMode;
	public:
		ScavTrap( void );
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap&	operator=(const ScavTrap& other);
		void		guardGate( void );
		void		attack(const std::string& target);
};
