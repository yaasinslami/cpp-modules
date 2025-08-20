#pragma once

#include "AMateria.hpp"
#include <iostream>

class	IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(IMateriaSource const &copy);
		virtual					~IMateriaSource();
		IMateriaSource&			operator=(IMateriaSource const &copy);

		virtual void			learnMateria(AMateria*) = 0;
		virtual AMateria*		createMateria(std::string const & type) = 0;
};
