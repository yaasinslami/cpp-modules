#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <iostream>
#include <stdexcept>

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		std::string		getTarget( void ) const;
		virtual void	executeAction( void ) const;

		void	print(std::ostream& os) const;

		class	RobotomyFailed : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	_target;
};

#endif