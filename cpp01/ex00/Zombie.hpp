/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 18:50:54 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 19:25:50 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		Zombie( std::string name );
		~Zombie();
		void announce( void );
		Zombie* newZombie( std::string name );
		void randomChump( std::string name );
};