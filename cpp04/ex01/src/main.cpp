#include "../inc/Brain.hpp"
#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

#define NB 4

void f(void) { system("leaks BrainAnimals"); }

int	main()
{
	// atexit(f);
	{
		std::cout << "\n--------------- main test of Brain ---------------" << std::endl;
		Animal*	animals[NB];

		for (int i = 0; i < NB; i++)
		{
			if (i < (NB / 2))
				animals[i] = new Dog("BrainedDog");
			else
				animals[i] = new Cat("BrainedCat");
			std::cout << std::endl;
		}

		Brain& DogBrain = animals[1]->getBrain();
		Brain& CatBrain = animals[3]->getBrain();

		DogBrain.setIdea(0, "I want to eat!");
		CatBrain.setIdea(1, "Today is sunny!");

		std::cout << "---------------- Can we see each animal idea !? ----------------" << std::endl;
		std::cout << "-> Brain owner: " << DogBrain.getOwner()
					<< ", idea[0]: " << DogBrain.getIdea(0) << std::endl;
		std::cout << "-> Brain owner: " << DogBrain.getOwner()
					<< ", idea[1]: " << DogBrain.getIdea(1) << std::endl;
		std::cout << "-> Brain owner: " << CatBrain.getOwner()
					<< ", idea[0]: " << CatBrain.getIdea(0) << std::endl;
		std::cout << "-> Brain owner: " << CatBrain.getOwner()
					<< ", idea[1]: " << CatBrain.getIdea(1) << std::endl;

		std::cout << "\n---------------- Check Deep Copies ----------------" << std::endl;
		
		// my idea is to work with Dog and Cats from previous Animals array

		// Animal* animalp = new Dog("BoB");

		// Dog *obj = dynamic_cast<Dog*>(animals[0]);
		// Dog objdOG = Dog();
		// objdOG = *obj;
		// Brain	_brain = obj->getBrain();

		// std::cout << "Brain owner: " << _brain.getOwner()
		// 			<< ", idea[0]: " << _brain.getIdea(20) << std::endl;



		std::cout << "\n------------------- Delete Animal Array Objects -------------------" << std::endl;
		
		for (int i = 0; i < NB; ++i)
		{
			delete animals[i];
			std::cout << std::endl;
		}
	}

	return 0;
}
