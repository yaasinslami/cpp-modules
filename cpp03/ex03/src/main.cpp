#include "DiamondTrap.hpp"

int	main( void )
{
	std::cout << "\n--- Default constructor ---" << std::endl;
    DiamondTrap dt_default;
    dt_default.whoAmI();
    dt_default.attack("TargetDummy");
    dt_default.takeDamage(30);
    dt_default.beRepaired(10);

    std::cout << "\n--- Parameterized constructor ---" << std::endl;
    DiamondTrap dt_param("Shiny");
    dt_param.whoAmI();
    dt_param.attack("ScaryMonster");
    dt_param.takeDamage(20);
    dt_param.beRepaired(5);

    std::cout << "\n--- Copy constructor ---" << std::endl;
    DiamondTrap dt_copy(dt_param);
    dt_copy.whoAmI();

    std::cout << "\n--- Assignment operator ---" << std::endl;
    DiamondTrap dt_assign;
    dt_assign = dt_default;
    dt_assign.whoAmI();

    std::cout << "\n--- Multiple attacks to test energy ---" << std::endl;
    for (int i = 0; i < 6; i++) {
        dt_param.attack("SpamTarget");
    }

    std::cout << "\n--- End of main ---" << std::endl;
}
