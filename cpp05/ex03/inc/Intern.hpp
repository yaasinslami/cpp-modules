#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class	AForm;

class	Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);

		AForm*	makeForm(const std::string& form_name, const std::string& form_target) const;

	private:
		AForm* createShrubbery(const std::string &target) const;
		AForm* createRobotomy(const std::string &target) const;
		AForm* createPresidential(const std::string &target) const;
};

#endif