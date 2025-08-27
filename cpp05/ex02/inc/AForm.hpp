#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <stdexcept>

class	Bureaucrat;

class	AForm
{
	public:
		AForm( void );
		AForm(const std::string& name, const int sign_grade, const int exec_grade);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);

		std::string	getName( void ) const;
		int			getSignGrade( void ) const;
		int			getExecGrade( void ) const;
		bool		getSigned( void ) const;

		void	beSigned(const Bureaucrat& b);
		void	execute(Bureaucrat const& executor) const;
		virtual void		executeAction() const = 0;

		virtual void print(std::ostream& os) const = 0;

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
		class	FormNotSignedException : public std::exception
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

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif