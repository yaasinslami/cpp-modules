/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:02:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:07:05 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon
{
	private:
		std::string	type;
	public:
		Weapon(const std::string &type);
		~Weapon(void);
		std::string const&	getType(void) const;
		void				setType(std::string const type);
};

#endif