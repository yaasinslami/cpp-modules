#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdexcept>

class	Bureaucrat;

class	Form
{
	public:
		Form( void );
		Form(const std::string& name, const int sign_grade, const int exec_grade);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		std::string	getName( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;
		bool		getSigned( void ) const;

		void	beSigned(const Bureaucrat& b);

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
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_signed;
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif