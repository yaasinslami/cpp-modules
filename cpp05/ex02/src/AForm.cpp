#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm( void ) : _name("defaultAForm"), _sign_grade(150), _exec_grade(150), _signed(false) {}

AForm::AForm(const std::string& name, const int sign_grade, const int exec_grade) : _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade > 150 || exec_grade > 150)
		throw GradeTooLowException();
	if (sign_grade < 1 || exec_grade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm& other) : _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
	*this = other;
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_signed = other._signed;
	return (*this);
}

std::string	AForm::getName( void ) const
{
	return (this->_name);
}

int	AForm::getSignGrade( void ) const
{
	return (this->_sign_grade);
}

int	AForm::getExecGrade( void ) const
{
	return (this->_exec_grade);
}

bool	AForm::getSigned( void ) const
{
	return (this->_signed);
}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() <= getSignGrade())
		this->_signed = true;
	else
		throw	GradeTooLowException();
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (getSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > getExecGrade())
		throw	AForm::GradeTooLowException();

	executeAction();
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form isn't signed yet!");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	f.print(os);
	return os;
}