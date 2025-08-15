#pragma once

#include "Animal.hpp"
#include <iostream>

class	Cat : public Animal
{
	private:
		std::string	_name;
	public:
		Cat( void );
		Cat(const std::string& type);
		Cat(const Cat& other);
		~Cat();
		Cat&	operator=(const Cat& other);

		std::string const	&getName(void) const;

		void		makeSound( void ) const;
};
