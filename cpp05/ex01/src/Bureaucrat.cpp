#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const	std::string&	Bureaucrat::getName( void ) const
{
	return this->_name;
}

int	Bureaucrat::getGrade( void ) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (getGrade() == 1)
	{
		// Already at the top
		throw	GradeTooHighException();
	}
	this->_grade--; // smaller number = higher grade
	
}

void	Bureaucrat::decrementGrade( void )
{
	if (_grade == 150)
	{
		// Already at the bottom
		throw GradeTooLowException();
	}
	_grade++; // bigger number = lower grade
}

void	Bureaucrat::signForm(Form& f) const
{
	try
	{
		f.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << "." << std::endl; 
		throw;
	}
	std::cout << getName() << " signed " << f.getName() << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}
