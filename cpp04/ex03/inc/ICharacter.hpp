#pragma once

#include <string>

class	AMateria;

class ICharacter
{
	public:
		ICharacter( void );
		ICharacter(const ICharacter& other);
		ICharacter&	operator=(const ICharacter& other);
		virtual ~ICharacter();

		virtual std::string const &getName() const = 0;
		
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
		virtual bool isInBag(AMateria* m) = 0;
};
