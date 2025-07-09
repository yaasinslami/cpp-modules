/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:24:35 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 17:16:18 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0)
		return (NULL);

	Zombie*	zombie_hord = new Zombie[N];
	if (!zombie_hord)
		return (NULL);

	for (int i = 0; i < N; i++)
	{
		zombie_hord[i].set_name(name);
	}

	return zombie_hord;
}
