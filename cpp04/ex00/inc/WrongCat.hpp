#pragma once

#include "WrongAnimal.hpp"
#include <iostream>

class	WrongCat : public WrongAnimal
{
	private:
		std::string	_name;
	public:
		WrongCat( void );
		WrongCat(const std::string& type);
		WrongCat(const WrongCat& other);
		~WrongCat();
		WrongCat&	operator=(const WrongCat& other);

		std::string const	&getName(void) const;

		void		makeSound( void ) const;
};
