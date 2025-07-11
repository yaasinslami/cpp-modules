/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:17:11 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:05:01 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string const	name;
		Weapon const		*_weapon;
	public:
		HumanB(std::string const& name);
		~HumanB(void);

		void	attack( void ) const;
		void	setWeapon(Weapon &weapon);
};


#endif