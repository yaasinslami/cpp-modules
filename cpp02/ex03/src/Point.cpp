/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:42:07 by yslami            #+#    #+#             */
/*   Updated: 2025/07/25 11:30:44 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}

Point::~Point() {}

Point::Point(const Fixed _x, const Fixed _y) : x(_x), y(_y) {}

Point::Point(const Point& other) : x(other.getX()), y(other.getY()) {}

Point&  Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Fixed	Point::getX() const
{
	return	this->x;
}

Fixed	Point::getY() const
{
	return this->y;
}

std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << "(" << point.getX() << ", " << point.getY() << ")";
	return os;
}
