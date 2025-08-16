#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << "------------- Dogs Scope -------------" << std::endl;

		Animal*	animalp = new Dog("BoB");
		std::cout << "Animal type: " << animalp->getType() << std::endl;
		animalp->makeSound();

		Dog	dog("Jack");
		dog.makeSound();

		dog = *static_cast<Dog*>(animalp);
		dog.makeSound();

		delete animalp;
	}

	{
		std::cout << "------------- Cats Scope -------------" << std::endl;

		Cat	cat("Slicy"), cat2("Foo");
		cat.makeSound();
		cat = cat2;
		std::cout << "Animal type: " << cat.getType() << std::endl;
		cat.makeSound();
	}

	{
		std::cout << "------------- Wrong Scope -------------" << std::endl;

		const WrongAnimal& wcat = WrongCat("WrongCatty");

		wcat.makeSound();
	}
	return 0;
}
