#pragma once

#include <iostream>
#include "Brain.hpp"

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
		virtual Brain&		getBrain( void ) const = 0;
		virtual void		makeSound( void ) const = 0;
		virtual void		logIdea(int idx) const = 0;
};
