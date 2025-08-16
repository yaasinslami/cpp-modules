#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class	Dog : public Animal
{
	private:
		std::string	_name;
		Brain		*_brain;
	public:
		Dog( void );
		Dog(const std::string& type);
		Dog(const Dog& other);
		~Dog();
		Dog&	operator=(const Dog& other);

		std::string const	&getName(void) const;
		void				setName(const std::string& name);
		Brain&				getBrain( void ) const;
		void				setBrain(const Brain& otherBrain);
		void				logIdea(int idx) const;

		void		makeSound( void ) const;
};
