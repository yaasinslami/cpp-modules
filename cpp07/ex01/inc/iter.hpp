#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename T_f>
void	iter(T* arr, size_t size, T_f func)
{
	if (!arr || !size || !func)
		return ;

	for (size_t i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif
