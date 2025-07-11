/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:29:25 by yslami            #+#    #+#             */
/*   Updated: 2025/07/10 10:55:10 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

static std::string	trim(const std::string& str) 
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && std::isspace(str[start]))
        start++;

    while (end > start && std::isspace(str[end - 1]))
        end--;

    return str.substr(start, end - start);
}

static bool is_valid_number(const std::string& str)
{
	if (str.empty()) return false;

	size_t i = 0;

	if (str[0] == '+')
	{
		if (str.length() == 1) return false; // "+" alone is invalid
		i = 1;
	}

	if (str[i] == '0' && str.length() - i > 1)
		return false;

	for (; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return false;
	}

	return true;
}

static int	getZombiesNb(void)
{
	int			nb;
	std::string	line;

	std::cout << "How many zombies would you like to summon into the horde? "
			<< std::endl;
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, line))
		{
			std::cout << std::endl;
			return -1;
		}

		if (!is_valid_number(trim(line)))
		{
			std::cout << "❌ Invalid input. Please enter a positive number only.\n";
			continue;
		}

		nb = std::atoi(line.c_str());
		if (nb < LIMIT_MIN || nb > LIMIT_MAX)
		{
			std::cout << "⚠️ Please choose a number between " << LIMIT_MIN << " and " << LIMIT_MAX << ".\n";
			continue;
		}
		break ;
	}
	return nb;
}

static bool is_valid_name(const std::string& str)
{
	if (str.empty())
		return false;

	bool has_alpha = false;

	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		char c = str[i];

		if (!std::isprint(static_cast<unsigned char>(c)))
			return false;

		if (std::isalpha(static_cast<unsigned char>(c)))
			has_alpha = true;
	}

	return has_alpha;
}

static std::string	getZombiesName(void)
{
	std::string	name;

	while (true)
	{
		std::cout << "Give your zombie a name: ";
		if (!std::getline(std::cin, name))
		{
			std::cout << std::endl;
			return "";
		}

		if (!is_valid_name(trim(name)))
		{
			std::cout << "Invalid name. Please use printable characters only." << std::endl;
			continue;
		}
		break ;
	}
	return name;
}

int	main(void)
{
	std::string	name;
	int			num;

	if (((num = getZombiesNb()) == -1) || (name = getZombiesName()).empty())
		return 0;

	Zombie	*army = zombieHorde(num, name);
	if (!army)
	{
		std::cout << "The Zombies horde failed!" << std::endl;
		return 1;
	}

	for (int i = 0; i < num; i++)
		army[i].announce();

	delete[] army;
	return 0;
}
