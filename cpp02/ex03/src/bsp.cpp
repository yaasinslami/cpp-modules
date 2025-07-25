/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:53:04 by yslami            #+#    #+#             */
/*   Updated: 2025/07/25 11:58:23 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area(Point const& p1, Point const& p2, Point const& p3)
{
	return Fixed(
		(p1.getX() * (p2.getY() - p3.getY()) +
		p2.getX() * (p3.getY() - p1.getY()) +
		p3.getX() * (p1.getY() - p2.getY())).toFloat() / 2.0f
	);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed	total = area(a, b, c);
	Fixed	area1 = area(a, b , point);
	Fixed	area2 = area(a, point , c);
	Fixed	area3 = area(point, b, c);

	Fixed	sum = area1.abs() + area2.abs() + area3.abs();

	if (area1 != Fixed(0.0f) && area2 != Fixed(0.0f) && area3 != Fixed(0.0f)
		&& sum == total.abs())
		return true;
	return false;
}
