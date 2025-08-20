#pragma once

#include <iostream>
#include "ICharacter.hpp"
class ICharacter;

class	AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria( void );
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		virtual ~AMateria();

		AMateria&	operator=(const AMateria& other);

		/* getter */
		std::string const	&getType() const;

		virtual void		use(ICharacter &target);
		virtual AMateria	*clone( void ) const = 0;
};
