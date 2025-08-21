#pragma once

#include "ICharacter.hpp"
#include <iostream>

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_bag[4];
	public:
		Character( void );
		Character(const std::string& name);
		Character(const Character& other);
		~Character();
		Character& operator=(const Character& other);

		std::string const &getName( void ) const;
		void				setName(const std::string& name);
		
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		bool	isInBag(AMateria *m);
};
