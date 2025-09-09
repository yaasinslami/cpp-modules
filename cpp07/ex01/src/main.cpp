#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(T a)
{
	std::cout << a << " ";
}

void	increment(int& i)
{
	i++;
}

int	main()
{
	const int arr[5] = {4, 1, 0, 7, -1};
	iter(arr, 5, increment);

	iter(arr, 5, print<int>);
}

