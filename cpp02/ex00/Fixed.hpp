/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:23:42 by yslami            #+#    #+#             */
/*   Updated: 2025/07/21 10:52:48 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_frac_bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
