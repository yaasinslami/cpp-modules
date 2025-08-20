#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void f(void) { system("leaks materia"); }

int	main()
{
	// atexit(f);

	/*
	std::cout << "\n----------------------- Basic Test -----------------------" << std::endl;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << "\n----------------------- Stress tests -----------------------" << std::endl;
	{
		Character	enemy1 = Character("BoB");
		ICharacter*	enemy0 = new Character;

		*static_cast<Character*>(enemy0) = enemy1;

		ICharacter*	pl = new Character("Jack");
	
		AMateria*	ice0 = new Ice();
		AMateria*	cure0 = new Cure();
		IMateriaSource* mSource = new MateriaSource();

		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Ice());
		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Cure());
		mSource->learnMateria(ice0);
		ice0 = new Ice();
		pl->equip(ice0);
		pl->equip(ice0);
		pl->equip(cure0);
		pl->equip(new Cure());
		pl->unequip(1);
		delete cure0;
		pl->unequip(4);
		pl->use(0, *enemy0);
		pl->use(1, *enemy0);
		pl->use(0, *pl);
		pl->use(5, *enemy0);

		delete enemy0;
		delete pl;
		delete	mSource;
	}
	*/

	{
		MateriaSource src0 = MateriaSource();
		Ice	ice = Ice();
		src0.learnMateria(&ice);
		// src0.learnMateria(&ice);
		// src0.learnMateria(&ice);
		// MateriaSource src1 = MateriaSource();
		// src1 = src0;
	}

	return 0;
}
