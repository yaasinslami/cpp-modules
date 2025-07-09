/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:21:38 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 15:22:58 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie*	z1 = newZombie("Zeth");
	Zombie*	z2 = newZombie("Z-41");
	Zombie*	z3 = newZombie("Necron");

	randomChump("Chonky");
	randomChump("Boop");
	randomChump("Dragg");

	z1->announce();
	z2->announce();
	z3->announce();

	delete z1;
	delete z2;
	delete z3;

	return 0;
}
