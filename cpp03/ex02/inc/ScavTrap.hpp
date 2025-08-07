#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
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
};
