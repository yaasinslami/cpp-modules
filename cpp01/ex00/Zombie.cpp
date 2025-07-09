/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:53:09 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 14:54:00 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "☠️  A wild zombie with no name has crawled out of the ground!" << std::endl;
	return ;
}

Zombie::Zombie(std::string name) :_name(name)
{
	std::cout << "A zombie named ["
				<< this->_name << "] has risen from the grave!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << this->_name
			<< ": I'm dying... again?! This sucks..." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
