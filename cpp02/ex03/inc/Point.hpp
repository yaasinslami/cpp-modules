/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:59:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/25 11:31:02 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		~Point();
		Point(const Fixed _x, const Fixed _y);
		Point(const Point& other);
		Point&  operator=(const Point& other);
		Fixed	getX() const;
		Fixed	getY() const;
};

std::ostream&	operator<<(std::ostream& os, const Point& obj);
