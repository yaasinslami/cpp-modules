/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:42:55 by yslami            #+#    #+#             */
/*   Updated: 2025/07/25 11:57:56 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(5.0f, 10.0f);

	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "A: " << a << std::endl;
	std::cout << "B: " << b << std::endl;
	std::cout << "C: " << c << std::endl;

	Point	p1(5.0f, 5.0f);
	std::cout << "the Point: " << p1 << " is ";
	std::cout << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle" << std::endl;

	return 0;
}
