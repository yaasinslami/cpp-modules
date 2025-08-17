#include "Ice.hpp"

Ice::Ice( void ) : AMateria("ice") {}

Ice::Ice(const Ice& other) {}

AMateria*	Ice::clone() const { return (new Ice(*this)); }

void	AMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
