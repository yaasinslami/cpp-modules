/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:29:25 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 19:09:24 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	getZombiesNb(void)
{
	int			nb;
	std::string	line;

	while (true)
	{
		std::cout << "How many zombies would you like to summon into the horde? ";
		if (!std::getline(std::cin, line))
			return -1;
		if (line.empty() ||)
	}
}

int	main(void)
{
	std::string	name;
	int			num;

	num = getZombiesNb();
	name = getZombiesName();

	
}
