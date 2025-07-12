/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:47:02 by yslami            #+#    #+#             */
/*   Updated: 2025/07/12 14:10:03 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FileReplacer.hpp"

static std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, last - first + 1);
}

static bool	HandleInput(int ac, char **av, std::string &filename,
	std::string &s1, std::string &s2)
{
	if (ac != 4)
	{
		std::cout << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return false;
	}

	filename = trim(av[1]);
	s1 = av[2];
	s2 = av[3];
	if (filename.empty() || !s1.length())
	{
		std::cout << "Error: field cannot be empty or whitespace only." << std::endl;
		return false;
	}
	return true;
}

int	main(int ac, char **av)
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (!HandleInput(ac, av, filename, s1, s2))
		return 1;

	std::cin.setstate(std::ios::eofbit);
	FileReplacer replacer(filename, s1, s2);
	if (!replacer.process())
	{
		std::cout << "Replacement failed." << std::endl;
		return 1;
	}
	else
		std::cout << "Replacement successful: " << filename << ".replace created." << std::endl;

	return 0;		
}
