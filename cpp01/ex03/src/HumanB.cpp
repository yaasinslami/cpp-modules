/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:57:19 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:06:29 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string const& _name) : name(_name), _weapon(NULL)
{
	std::cout << this->name 
			<<" kicks down the door to the Arena with his [hands]"
			<< std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->name << " leave the Arena";
	if (this->_weapon && !this->_weapon->getType().empty())
		std::cout << " with his [" << this->_weapon->getType() << "]";
	std::cout << std::endl;
}

void	HumanB::attack(void) const
{
	std::cout << this->name;
	if (this->_weapon && !this->_weapon->getType().empty())
		std::cout << " attack with their [" << this->_weapon->getType() << "]";
	else
		std::cout << " delivers a savage unarmed attack!";
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	if (!weapon.getType().empty())
	{
		if (!this->_weapon || this->_weapon->getType().empty())
			std::cout 
				<< this->name << " arms themselves with a [" 
				<< weapon.getType() << "]"
				<< std::endl;
		else
			std::cout 
				<< this->name << " tosses their old weapon and equips a ["
				<< weapon.getType() << "]"
				<< std::endl;
	}
	else
	{
		// case they do nothing
		if (!this->_weapon || this->_weapon->getType().empty())
			std::cout
				<< this->name << " is unable to equip any weapon!"
				<< std::endl;
	 	// case they drop their weapons
		else
			std::cout << this->name
				<< " puts away his weapon: [" << this->_weapon->getType() << "]"
				<< std::endl;
	}
	if (weapon.getType().empty())
		this->_weapon = NULL;
	else
		this->_weapon = &weapon;
}
