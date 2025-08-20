#pragma once

#include "AMateria.hpp"
#include <iostream>


class	Cure : public AMateria
{
	public:
		Cure( void );
		Cure(const Cure& other);
		~Cure();
		Cure&	operator=(const Cure& other);

		void		use(ICharacter &target);
		AMateria	*clone() const;
};
