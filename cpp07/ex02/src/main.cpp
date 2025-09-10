#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 750
int main(void)
{

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
	std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	delete [] mirror;

	// empty Array
	{
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
		std::cout << "Empty array contents: " << empty << std::endl;

		// Accessing an element should throw
		try
		{
			std::cout << "Trying to access empty[0]: " << empty[0] << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
    return 0;
}

