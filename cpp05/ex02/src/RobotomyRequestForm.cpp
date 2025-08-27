#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("defaultRobot")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return (*this);
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void	RobotomyRequestForm::executeAction( void ) const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	if (rand() % 2)
		std::cout << getTarget() << " has been robotomized successfully!" << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailed();
};

const char*	RobotomyRequestForm::RobotomyFailed::what() const throw()
{
	return ("The Robotomy Failed");
}

void	RobotomyRequestForm::print(std::ostream& os) const
{
	os << "RobotomyRequest_Form \"" << getName() << "\""
	<< " [Sign grade: " << getSignGrade()
	<< ", Exec grade: " << getExecGrade()
	<< ", Signed: " << (getSigned() ? "Yes" : "No") << ", Target: " << getTarget() << "]." << std::endl;
}
