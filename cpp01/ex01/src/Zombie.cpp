/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:16:43 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 18:28:38 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "a zombie has risen from the grave!" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{ 
	std::cout << "A zombie named " << this->_name << " appeared!" << std::endl;
	return ;
}

Zombie::~Zombie()
{
	std::cout << this->_name << ": has returned to the grave..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}
