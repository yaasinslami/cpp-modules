#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdexcept>

Intern::Intern( void ) {}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern() {}

AForm *Intern::createShrubbery(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidential(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& form_name, const std::string& form_target) const try
{
	static const	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	typedef AForm *(Intern::*Creator)(const std::string &target) const;
	static const Creator creators[] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	int i = 0;
	while (i < 3 && form_name != names[i])
		i++;

	if (i < 3)
	{
		AForm* form = NULL;
		form = (this->*creators[i])(form_target);
		std::cout << "Intern creates " << form_name << std::endl;
		return form;
	}

	std::cerr << "Intern couldn't find the form: " << form_name << std::endl;
	return NULL;
}
catch(std::exception &e)
{
	std::cerr << "Intern failed to create form due to: " << e.what() << std::endl;
	return NULL;
}