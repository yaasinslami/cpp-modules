#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int	main()
{
	std::cout << "\n-------------- Character Test --------------" << std::endl;
	{
		Character jack("Jack");
		AMateria* ice = new Ice();
		jack.equip(ice);
		jack.equip(new Cure());

		Character jackCopy(jack);
		jackCopy.setName("jackCopy");
		jackCopy.equip(new Ice());
		jackCopy.use(0, jack);
		jackCopy.use(1, jack);

		jack.unequip(0);
		delete ice;
		jack.use(0, jackCopy);
		jackCopy.use(0, jack);

		jackCopy = jack;
		jackCopy.use(0, jack);
	}

	std::cout << "\n-------------- MateriaSource Test --------------" << std::endl;
	{
		MateriaSource src1;
		src1.learnMateria(new Ice());
		src1.learnMateria(new Cure());

		MateriaSource src2(src1);
		MateriaSource src3 = src2;
		AMateria *c1 = src3.createMateria("cure");
		AMateria *i1 = src3.createMateria("ice");

		Character me("me"), pl("BoB");
		me.equip(c1);
		me.equip(i1);
		me.use(0, pl);
		me.use(1, pl);
	}

	std::cout << "\n--------------------------------------------" << std::endl;
	{
		IMateriaSource*	mSource = new MateriaSource();
		ICharacter*	pl = new Character("Jack");
		Character enemy = Character("BoB");

		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Ice());
		mSource->learnMateria(new Cure());
		mSource->learnMateria(new Cure());

		AMateria *ice = mSource->createMateria("ice");
		AMateria *cure = mSource->createMateria("cure");
		AMateria *other = mSource->createMateria("falseMateria");
		if (other == 0)
			std::cout << "createMateria return 0" << std::endl;
	
		pl->equip(ice);
		pl->equip(ice);
		pl->equip(cure);
		pl->equip(other);

		pl->unequip(1);
		delete cure;
		pl->unequip(4);

		pl->use(0, *pl);
		pl->use(2, enemy);
		pl->use(0, enemy);
		pl->use(1, enemy);
		pl->use(5, enemy);

		delete pl;
		delete mSource;
	}

	return 0;
}
