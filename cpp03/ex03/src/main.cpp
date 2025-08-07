#include "FragTrap.hpp"

int	main( void )
{
	FragTrap ft1("Fraggy");
	ft1.showStatus();
	ft1.highFivesGuys();

	FragTrap ft2 = ft1;
	FragTrap ft3;
	ft3 = ft1;

	return 0;
}
