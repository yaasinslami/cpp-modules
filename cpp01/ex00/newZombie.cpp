/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:57:21 by yslami            #+#    #+#             */
/*   Updated: 2025/07/15 08:51:56 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	if (!zombie)
	{
		std::cout << "Failed to Create The Zombie " << name << std::endl;
		return NULL;
	}
	zombie->announce();
	return (zombie);
}
