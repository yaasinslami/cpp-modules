#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
try
{
	// Seed random for RobotomyRequestForm
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== Creating Bureaucrats ===" << std::endl;
	Bureaucrat jack("Jack", 1); // high grade
	Bureaucrat jim("Jim", 150); // low grade
	std::cout << jack << std::endl;
	std::cout << jim << std::endl;

	std::cout << "\n=== Creating Intern ===" << std::endl;
	Intern someRandomIntern;

	// Test RobotomyRequestForm
	std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
	AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		try
		{
			jack.signForm(*rrf);	// should succeed
			jim.executeForm(*rrf);	// should fail
			jack.executeForm(*rrf); // executes action
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		delete rrf;
	}

	// Test ShrubberyCreationForm
	std::cout << "\n=== ShrubberyCreationForm ===" << std::endl;
	AForm *shrub = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (shrub)
	{
		std::cout << *shrub << std::endl;
		try
		{
			jack.signForm(*shrub);
			jack.executeForm(*shrub);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		delete shrub;
	}

	// Test PresidentialPardonForm
	std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Alice");
	if (pardon)
	{
		std::cout << *pardon << std::endl;
		try
		{
			jim.signForm(*pardon);	// should fail
			jack.signForm(*pardon); // should succeed
			jack.executeForm(*pardon);
		}
		catch (std::exception &e)
		{
			std::cerr << "Exception: " << e.what() << std::endl;
		}
		delete pardon;
	}

	// Test unknown form
	std::cout << "\n=== Unknown Form ===" << std::endl;
	AForm *unknown = someRandomIntern.makeForm("unknown form", "Nobody");
	if (!unknown)
		std::cout << "Returned NULL for unknown form." << std::endl;

	return 0;
}
catch (std::exception &e)
{
	std::cerr << "Caught exception in main: " << e.what() << std::endl;
	return 1;
}
