#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form( void ) : _name("defaultForm"), _sign_grade(150), _exec_grade(150), _signed(false) {}

Form::Form(const std::string& name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form& other) : _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	*this = other;
}

Form::~Form() {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::string	Form::getName( void ) const
{
	return (this->_name);
}

int	Form::getSignGrade( void ) const
{
	return (this->_sign_grade);
}

int	Form::getExecGrade( void ) const
{
	return (this->_exec_grade);
}

bool	Form::getSigned( void ) const
{
	return (this->_signed);
}

void	Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= getSignGrade())
		this->_signed = true;
	else
		throw	GradeTooLowException();
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form \"" << f.getName() << "\""
	   << " [Sign grade: " << f.getSignGrade()
	   << ", Exec grade: " << f.getExecGrade()
	   << ", Signed: " << (f.getSigned() ? "Yes" : "No") << "]." << std::endl;
	return os;
}
