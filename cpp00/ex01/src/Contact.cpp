/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:44:09 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 16:04:39 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::get_fname(void) const
{
	return this->fname;
}

std::string	Contact::get_lname(void) const
{
	return this->lname;
}

std::string	Contact::get_phone(void) const
{
	return this->phone;
}

std::string	Contact::get_nickname(void) const
{
	return this->nickname;
}

std::string	Contact::get_secret(void) const
{
	return this->secret;
}

void	Contact::set_fname(const std::string& _fname)
{
	this->fname = _fname;
}

void	Contact::set_lname(const std::string& _lname)
{
	this->lname = _lname;
}

void	Contact::set_nickname(const std::string& _nickname)
{
	this->nickname = _nickname;
}

void	Contact::set_phone(const std::string& _phone)
{
	this->phone = _phone;
}

void	Contact::set_secret(const std::string& _secret)
{
	this->secret = _secret;
}

