/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Harl.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:25:47 by yslami            #+#    #+#             */
/*   Updated: 2025/07/12 15:55:14 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		Harl();
		~Harl();
		void	complain( std::string level );
};

#endif