/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 19:44:09 by yslami            #+#    #+#             */
/*   Updated: 2025/07/06 16:38:26 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

/* getters */
std::string	Contact::get_fname(void) const
{
	return fname;
}

std::string	Contact::get_lname(void) const
{
	return lname;
}

std::string	Contact::get_phone(void) const
{
	return phone;
}

std::string	Contact::get_nickname(void) const
{
	return nickname;
}

std::string	Contact::get_secret(void) const
{
	return secret;
}

/* setters */
void	Contact::set_fname(const std::string& _fname)
{
	this->fname = _fname;
}

void	Contact::set_lname(const std::string& _lname)
{
	lname = _lname;
}

void	Contact::set_nickname(const std::string& _nickname)
{
	nickname = _nickname;
}

void	Contact::set_phone(const std::string& _phone)
{
	phone = _phone;
}

void	Contact::set_secret(const std::string& _secret)
{
	secret = _secret;
}

