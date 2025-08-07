#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	player1("P1");

	player1.attack("P2");
	player1.takeDamage(100);
	player1.attack("P3");
	player1.beRepaired(50);

	return 0;
}
