#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << "\n------------ throw exception in Form constructor: ------------" << std::endl;
	try
	{
		Form		wrong_form =  Form("wati9a_rassmiya", -1, 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	Bureaucrat	b = Bureaucrat("BoB", 13);

	Form		original_form =  Form("wati9a_rassmiya", 12, 50);
	Form		f(original_form);

	std::cout << "\n------------ Bureaucrat && Form status ------------" << std::endl;
	std::cout << f;
	std::cout << b;

	std::cout << "\n------------ before increment Bureaucrat grade ------------" << std::endl;
	try
	{
		b.signForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n------------ after increment Bureaucrat grade ------------" << std::endl;
	try
	{
		b.incrementGrade();
		b.signForm(f);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\n------------ Bureaucrat && Form status ------------" << std::endl;
	std::cout << f;
	std::cout << b;
}
