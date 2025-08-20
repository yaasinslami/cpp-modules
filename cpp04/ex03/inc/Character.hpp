#pragma once

#include "ICharacter.hpp"

struct TrashNode
{
	AMateria *materia;
	TrashNode *next;

	TrashNode(AMateria* m, TrashNode* n) : materia(m), next(n) {}
};

class	Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria*	_bag[4];
		TrashNode*	_trashHead;
		void		addToTrash(AMateria* m);
	public:
		Character( void );
		Character(const std::string& name);
		Character(const Character& other);
		~Character();
		Character& operator=(const Character& other);

		std::string const &getName( void ) const;
		
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		bool	isInBag(AMateria *m);
};
