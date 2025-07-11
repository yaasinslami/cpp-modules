/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:22:01 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:06:58 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& _type) : type(_type)
{
	return ;
}

Weapon::~Weapon(void)
{
	// std::cout << "Weapon destroyed" << std::endl;
	return ;
}

std::string const&	Weapon::getType(void) const
{
	return this->type;
}

void	Weapon::setType(std::string const type)
{
	this->type = type;
}
