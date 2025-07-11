/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:07:32 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:07:44 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA(std::string const& _name, Weapon const &_weapon) : name(_name), weapon(_weapon)
{
	std::cout << this->name
				<< " kicks down the door to the Arena with a Spear"
				<< std::endl; 
}

HumanA::~HumanA(void)
{
	std::cout << this->name << " leave the Arena";
	if (!this->weapon.getType().empty())
		std::cout << " with their " << this->weapon.getType();
	std::cout << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout << this->name;
	if (this->weapon.getType() != "")
		std::cout << " attacks with their "
				<< this->weapon.getType() << "!";
	else
		std::cout << " delivers a savage unarmed attack!";
	std::cout << std::endl;
}
