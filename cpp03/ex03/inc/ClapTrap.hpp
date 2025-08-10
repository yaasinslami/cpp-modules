#pragma once

#include <iostream>

class	ClapTrap
{
	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
	public:
		ClapTrap( void );
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();
		ClapTrap		&operator=(const ClapTrap& other);
		void			attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void			showStatus( void ) const;
};
