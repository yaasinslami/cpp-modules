
#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j]; j++)
				std::cout << (char)toupper(av[i][j]);
			if (av[i + 1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
