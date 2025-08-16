#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Cat : public Animal
{
	private:
		std::string	_name;
		Brain		*_brain;
	public:
		Cat( void );
		Cat(const std::string& type);
		Cat(const Cat& other);
		~Cat();
		Cat&	operator=(const Cat& other);

		std::string const	&getName(void) const;
		void				setName(const std::string& name);
		Brain&				getBrain( void ) const;
		void				logIdea(int idx) const;

		void		makeSound( void ) const;
};
