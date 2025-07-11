/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:46:43 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:08:24 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
		std::cout << "\n==================== HumanA Always Armed"
				<< " ====================\n" << std::endl;

		Weapon sword("steel longsword");
		HumanA arthur("Arthur", sword);
		arthur.attack();

		std::cout << "(Weapon changes to 'enchanted longsword')" << std::endl;
		sword.setType("enchanted longsword");
		arthur.attack();
	}
	{
		std::cout << "\n==================== HumanB Optional Weapon"
				<< " ====================\n" << std::endl;

		Weapon axe("iron battle axe");
		HumanB ragnar("Ragnar");

		std::cout << "(Ragnar tries to attack without a weapon)" << std::endl;
		ragnar.attack();

		std::cout << "(Setting Ragnar's weapon to axe)" << std::endl;
		ragnar.setWeapon(axe);
		ragnar.attack();

		std::cout << "(Weapon changes to 'legendary axe of fury')" << std::endl;
		axe.setType("legendary axe of fury");
		ragnar.attack();
	}

	return 0;
}
