/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:07:24 by yslami            #+#    #+#             */
/*   Updated: 2025/07/22 17:27:43 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_frac_bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed(const int val);
		Fixed(const float val);
		Fixed&	operator=(const Fixed& other);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);
