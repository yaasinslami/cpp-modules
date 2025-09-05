#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <locale>

Base * generate(void)
{
	int	r = std::rand() % 3;

	if (r == 0)
	{
		std::cout << "A generated" << std::endl;
		return new A();
	}
	else if (r == 1)
	{
		std::cout << "B generated" << std::endl;
		return new B();
	}
	else
	{
		std::cout << "C generated" << std::endl;
		return new C();
	}
}

void	identify(Base* p)
{
	try
	{
		
	}
}

