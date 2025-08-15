#pragma once

#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal( void );
		Animal(const std::string& _type);
		Animal(const Animal& other);
		virtual ~Animal();
		Animal&	operator=(const Animal& other);

		std::string const	&getType(void) const;

		virtual void		makeSound( void ) const;
};
