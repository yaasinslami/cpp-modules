/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:16:34 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 11:04:50 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string const	name;
		Weapon const		&weapon;
	public:
		HumanA(std::string const& name, Weapon const &weapon);
		~HumanA(void);

		void	attack( void ) const;
};

#endif