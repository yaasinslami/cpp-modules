#include "ICharacter.hpp"

ICharacter::ICharacter(void) {}

ICharacter::ICharacter(ICharacter const &copy) { *this = copy; }

ICharacter::~ICharacter() {}

ICharacter&	ICharacter::operator=(const ICharacter& other)
{
	(void)other;
	return (*this);
}
