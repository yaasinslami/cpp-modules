#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("DEF")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		this->AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::executeAction( void ) const
{
	std::ofstream outFile(getTarget() + "_shrubbery");

	if (outFile)
	{
		outFile << "       _-_\n";
		outFile << "    /~~   ~~\\\n";
		outFile << " /~~         ~~\\\n";
		outFile << "{               }\n";
		outFile << " \\  _-     -_  /\n";
		outFile << "   ~  \\\\ //  ~\n";
		outFile << "_- -   | | _- _\n";
		outFile << "  _ -  | |   -_\n";
		outFile << "      // \\\\\n";

		outFile.close();
	}
	else
		throw ShrubberyCreationForm::FailedFileException();
}

const char*	ShrubberyCreationForm::FailedFileException::what() const throw()
{
	return ("Cannot create file!");
}

void	ShrubberyCreationForm::print(std::ostream& os) const
{
	os << "ShrubberyCreation_Form \"" << getName() << "\""
	<< " [Sign grade: " << getSignGrade()
	<< ", Exec grade: " << getExecGrade()
	<< ", Signed: " << (getSigned() ? "Yes" : "No") << ", Target: " << getTarget() << "]." << std::endl;
}
