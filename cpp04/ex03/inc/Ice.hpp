#pragma once
#include "AMateria.hpp"
#include <iostream>


class	Ice : public AMateria
{
	public:
		Ice( void );
		Ice(const Ice& other);
		~Ice();
		Ice&	operator=(const Ice& other);

		void		use(ICharacter &target);
		AMateria	*clone() const;
};
