#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void f(void) { system("leaks materia"); }

int	main()
{
	// atexit(f);

	ICharacter*	enemy = new Character("Jack");
	ICharacter*	pl = new Character("BoB");
	AMateria*	ice0 = new Ice();
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(ice0);
	AMateria* ic = src->createMateria("ice");
	pl->equip(ic);
	pl->equip(ic);
	pl->equip(NULL);
	pl->use(0, *enemy);
	pl->use(1, *enemy);

	delete enemy;
	delete pl;

	return 0;
}
