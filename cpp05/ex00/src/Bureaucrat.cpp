
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("DefaultBureaucrat"), _grade(150)
{
	std::cout << "[" << getName() << "] Created." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	this->_grade = grade;
	std::cout << "Bureaucrat [" << getName() << "] Created."
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
	std::cout << other.getName() << " has been copied successfully."
				<< std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "[" << other.getName() << "] assigned to ["
				<< getName() << "] Bureaucrat" << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat [" << getName() << "] Destroyed!"
		<< std::endl;
}

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
