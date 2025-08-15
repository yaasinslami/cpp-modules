#pragma once

#include "Animal.hpp"
#include <iostream>

class	Dog : public Animal
{
	private:
		std::string	_name;
	public:
		Dog( void );
		Dog(const std::string& type);
		Dog(const Dog& other);
		~Dog();
		Dog&	operator=(const Dog& other);

		std::string const	&getName(void) const;

		void		makeSound( void ) const;
};
