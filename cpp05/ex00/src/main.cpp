#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "\n------------- throw exception at Constructor step -------------" << std::endl;
	try {
		Bureaucrat	b = Bureaucrat("Clev", 200);
		b.decrementGrade();
		std::cout << b;
	}

	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n------------- Copy constructor -------------" << std::endl;
	try
	{
		Bureaucrat original("Frank", 42);
		Bureaucrat copy(original); // copy constructor
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy:     " << copy << std::endl;
		copy.incrementGrade();
		std::cout << "After increment copy: " << copy << std::endl;
		std::cout << "Original remains: " << original << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------------- throw exception by: incrementGrade() -------------" << std::endl;
	try {
		Bureaucrat	b = Bureaucrat("Jemmy", 1);
		b.decrementGrade();
		b.incrementGrade();
		std::cout << b;

		Bureaucrat c = Bureaucrat("BoB", 12);
		c = b;
		c.decrementGrade();
		std::cout << c;

		c.incrementGrade();
		c.incrementGrade();
	}

	catch (std::exception& e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
