#pragma once

#include <iostream>
# define IDEAS_NB 100

class	Brain
{
	private:
		std::string	_ideas[IDEAS_NB];
		std::string	_owner;
	public:
		Brain( void );
		Brain(const std::string& owner);
		Brain(const Brain& other);
		virtual ~Brain();
		Brain&	operator=(const Brain& other);

		void setIdea(int index, const std::string& idea);
		const std::string& getIdea(int index) const;
		void setOwner(const std::string& owner);
		const std::string& getOwner() const;
};
