
#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
		ScavTrap() { std::cout << "im ScavTrap" << std::endl; };
		~ScavTrap() { std::cout << "im ScavTrap destractor" << std::endl; }
};