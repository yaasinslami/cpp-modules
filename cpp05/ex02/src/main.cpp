#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() try
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	/* Create bureaucrats */
	// Bureaucrat failed_bure("Error", 0);
	Bureaucrat jack0("Jack", 1);
	Bureaucrat jack(jack0);
	Bureaucrat john("John", 50);
	Bureaucrat jane("Jane", 140);

	// jack0.incrementGrade();

	/* Create Forms */
	ShrubberyCreationForm shrub0("Garden");
	RobotomyRequestForm robo0("Street");
	RobotomyRequestForm robo20("Street2");
	PresidentialPardonForm pardon0("Alice");

	std::cout << "\n------------------------------------------------* Print Forms Status *-----------------------------------------" << std::endl;
	std::cout << shrub0;
	std::cout << std::endl;
	std::cout << robo0;
	std::cout << std::endl;
	std::cout << robo20;
	std::cout << std::endl;
	std::cout << pardon0;
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	std::cout << "\n=== Testing signing Form ===" << std::endl;
	jane.signForm(shrub0);
	jane.signForm(robo0);
	john.signForm(robo0);
	john.signForm(pardon0);
	jack.signForm(pardon0);
	jack.signForm(robo20);

	std::cout << "\n=== Testing executing Form ===" << std::endl;

	ShrubberyCreationForm shrub(shrub0);
	RobotomyRequestForm robo(robo0);
	RobotomyRequestForm robo2(robo20);
	PresidentialPardonForm pardon(pardon0);

	std::cout << "\n------------------------------------------------* Print Forms Status *-----------------------------------------" << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robo << std::endl;
	std::cout << robo2 << std::endl;
	std::cout << pardon;
	std::cout << "-------------------------------------------------------------------------------------------------------------\n" << std::endl;

	jane.executeForm(shrub);
	john.executeForm(shrub);
	jane.executeForm(robo);
	jack.executeForm(robo);
	jack.executeForm(robo2);
	jack.executeForm(pardon);

	std::cout << "\n=== Invalid executions ===" << std::endl;
	RobotomyRequestForm unsignedRobo("UnsignedTarget");
	jack.executeForm(unsignedRobo);

	return 0;
}
catch (std::exception &e)
{
	std::cerr << "Caught exception: " << e.what() << std::endl;
}
