#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(const T& a)
{
	std::cout << a << " " << std::endl;
}

void	increment(int& i)
{
	i++;
}

int	main()
{
	int arr[5] = {4, 1, 0, 7, -1};
	
	std::cout << "Before increment" << std::endl;
	iter(arr, 5, print<int>);

	iter(arr, 5, increment);

	std::cout << "After increment" << std::endl;
	iter(arr, 5, print<int>);
}

