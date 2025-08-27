#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm( void );
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		std::string		getTarget( void ) const;
		virtual	void	executeAction( void ) const;

		void	print(std::ostream& os) const;

		class	FailedFileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		std::string	_target;
};

#endif