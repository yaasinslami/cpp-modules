/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:40:15 by yslami            #+#    #+#             */
/*   Updated: 2025/07/12 16:40:18 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

static std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	if (first == std::string::npos)
		return "";

	size_t last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, last - first + 1);
}

int	main(int ac, char **av)
{
	Harl	harl;

	if (ac == 2)
		harl.complain(trim(av[1]));
	else
		std::cout << "Usage: ./harl5 <LEVEL>" << std::endl;

	return 0;
}
