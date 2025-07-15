/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:21:38 by yslami            #+#    #+#             */
/*   Updated: 2025/07/15 08:57:12 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie*	z1 = newZombie("Zeth");
	if (!z1)
		return 1;
	Zombie*	z2 = newZombie("Z-41");
	if (!z2)
	{
		delete z1;
		return 1;
	}
	Zombie*	z3 = newZombie("Necron");
	if (!z3)
	{
		delete z1;
		delete z2;
		return 1;		
	}

	randomChump("Chonky");
	randomChump("Boop");
	randomChump("Dragg");

	delete z1;
	delete z2;
	delete z3;

	return 0;
}
