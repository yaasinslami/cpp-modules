#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap	obj("Floki");
	ClapTrap	*br = &obj;
	br->attack("Siggy");
	br->takeDamage(10);
	br->beRepaired(5);
	obj.guardGate();
	br->showStatus();

	return 0;
}
