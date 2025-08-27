#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class	Bureaucrat
{
	public:
		Bureaucrat( void );
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string&	getName( void ) const;
		int		getGrade( void ) const;
		void 	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm(AForm& f) const;
		void	executeForm(AForm const & form) const;

		/* custsomized exceptions classes */
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		const std::string _name;
		int _grade;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
