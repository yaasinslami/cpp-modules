#pragma once

#include <iostream>

class	WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal( void );
		WrongAnimal(const std::string& _type);
		WrongAnimal(const WrongAnimal& other);
		~WrongAnimal();
		WrongAnimal&	operator=(const WrongAnimal& other);

		std::string const	&getType(void) const;

		void		makeSound( void ) const;
};
