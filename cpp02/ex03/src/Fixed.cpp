/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:40:55 by yslami            #+#    #+#             */
/*   Updated: 2025/07/25 10:11:14 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const	Fixed::_frac_bits = 8;

Fixed::Fixed( void ) : _value(0) {}

Fixed::~Fixed( void ) {}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int val)
{
	this->_value = val << this->_frac_bits;
}

Fixed::Fixed(const float val)
{
	this->_value = roundf(val * (1 << this->_frac_bits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return this->_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat( void ) const
{
	return	((float)this->_value / (1 << this->_frac_bits));
}

int	Fixed::toInt( void ) const
{
	return (this->_value >> this->_frac_bits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->toFloat() > other.toFloat());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->toFloat() < other.toFloat());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->toFloat() == other.toFloat());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._value = this->_value + other._value;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result._value = this->_value - other._value;
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;

	result._value = (this->_value * other._value) >> _frac_bits;
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;

	if (other._value == 0)
	{
		std::cout << "Error: Division by zero!" << std::endl;
		return Fixed();
	}
	result._value = (this->_value << _frac_bits) / other._value;
	return result;
}

Fixed	Fixed::operator++()
{
	++this->_value;
	return *this;
}

Fixed	Fixed::operator--()
{
	--this->_value;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	tmp = *this;
	++this->_value;
	return tmp;
}

Fixed	Fixed::operator--( int )
{
	Fixed	tmp = *this;
	--this->_value;
	return tmp;
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	return (f1.toFloat() > f2.toFloat()) ? f2 : f1;
}

const Fixed& 	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() > f2.toFloat()) ? f2 : f1;
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	return (f1.toFloat() > f2.toFloat()) ? f1 : f2;
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	return (f1.toFloat() > f2.toFloat()) ? f1 : f2;
}

Fixed	Fixed::abs() const
{
	return (this->_value < 0) ? Fixed(-this->toFloat()) : *this;
}

