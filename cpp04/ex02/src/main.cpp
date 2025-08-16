#include "Brain.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n--------------- Farm Main ---------------" << std::endl;

	Animal *animals[4];

	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog("BrainedDog");
		else
			animals[i] = new Cat("BrainedCat");
		std::cout << std::endl;
	}

	Dog&	dogg = *static_cast<Dog*>(animals[1]);
	Cat&	catt = *static_cast<Cat*>(animals[3]);

	dogg.makeSound();
	catt.makeSound();

	dogg.getBrain().setIdea(0, "I want to eat!");
	catt.getBrain().setIdea(1, "Today is sunny!");

	std::cout << "\n---------------- Can we see each animal idea !? ----------------" << std::endl;
	dogg.logIdea(0);
	dogg.logIdea(1);
	catt.logIdea(0);
	catt.logIdea(1);

	std::cout << "\n---------------- Check Deep Copies ----------------\n"
			  << std::endl;
	{
		std::cout << "----- Dogs (Assignment Operator) -----" << std::endl;
		Dog *dog0 = static_cast<Dog *>(animals[0]);
		Dog *dog1 = static_cast<Dog *>(animals[1]);
		dog0->setName("Jack");
		dog1->setName("BoB");

		*dog0 = *dog1;

		dog1->getBrain().setIdea(0, "No, I dont want to sleep");
		dog0->logIdea(0);
		dog1->logIdea(0);

		std::cout << "\n----- Dogs (Copy Constructor) -----" << std::endl;
		Dog copyDog(*dog1);
		copyDog.setName("CopyBoB");

		dog1->getBrain().setIdea(0, "I'm the real BoB!");
		copyDog.getBrain().setIdea(0, "I'm the copy BoB!");

		dog1->logIdea(0);
		copyDog.logIdea(0);
	}

	{
		std::cout << "\n----- Cats (Assignment Operator) -----" << std::endl;
		Cat *cat0 = static_cast<Cat *>(animals[2]);
		Cat *cat1 = static_cast<Cat *>(animals[3]);
		cat0->setName("Catty");
		cat1->setName("Simba");

		*cat0 = *cat1;

		cat1->getBrain().setIdea(1, "No, Today is cloudy!");
		cat0->logIdea(1);
		cat1->logIdea(1);

		std::cout << "\n----- Cats (Copy Constructor) -----" << std::endl;
		Cat copyCat(*cat1);
		copyCat.setName("CopySimba");

		cat1->getBrain().setIdea(1, "I'm the real Simba!");
		copyCat.getBrain().setIdea(1, "I'm the copy Simba!");

		cat1->logIdea(1);
		copyCat.logIdea(1);
	}

	std::cout << "\n------------------- Delete Animal Array Objects -------------------" << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	return 0;
}
