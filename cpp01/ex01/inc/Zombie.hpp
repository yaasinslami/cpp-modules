/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:07:29 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 17:54:03 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class	Zombie
{
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();
		Zombie(std::string name);
		void	announce(void);
		void	set_name(std::string name);
};

#endif