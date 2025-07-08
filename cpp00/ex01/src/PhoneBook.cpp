/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:06:31 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 17:51:15 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(void) :  index(0), count(0)
{
	printwelcome();
}

PhoneBook::~PhoneBook(void)
{	
	std::cout << "👋 Exiting PhoneBook..." << std::endl;
	std::cout << "All your contacts have vanished into 80s cyberspace!" << std::endl;
}

static std::string get_input(const std::string& prompt)
{
	std::string line;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, line))
			return ""; 

		line = trim(line);
		if (!line.empty())
			return line;
		std::cout << "❓ Invalid input: field cannot be empty or only whitespace." << std::endl;
	}
}

void	PhoneBook::add(void)
{
	std::cout << "📇 Adding a new contact..." << std::endl;

	const std::string prompts[5] = {
		"➡ Enter a first name: ",
		"➡ Enter a last name: ",
		"➡ Enter a nickname: ",
		"➡ Enter a phone number: ",
		"➡ Enter a darkest secret: "
	};

	typedef void (Contact::*Setter)(const std::string&);
	Setter setters[5] = {
		&Contact::set_fname,
		&Contact::set_lname,
		&Contact::set_nickname,
		&Contact::set_phone,
		&Contact::set_secret
	};

	Contact& c = contacts[index];
	std::string	line;

	for (int i = 0; i < 5; i++)
	{
		line = get_input(prompts[i]);
		if (line.empty()) return ;
		(c.*setters[i])(line);
	}

	std::cout << contacts[index].get_nickname() << " contact added! [" << index + 1 <<  "/8]" << std::endl;
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
}

void	PhoneBook::search(void)
{
	int			i = 0;
	std::string	_fname;
	std::string	_lname;
	std::string	_nick;
	std::string	_phone;
	std::string	_secret;
	std::string	line;

	if (!this->count)
	{
		std::cout << "📭 PhoneBook is empty. Please ADD some contacts first!" << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "FirstName" << "|"
			<< std::setw(10) << "LastName" << "|"
			<< std::setw(10) << "NickName" << "|"
			<< std::endl;
	while (i < this->count)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		_fname = this->contacts[i].get_fname();
		_lname = this->contacts[i].get_lname();
		_nick = this->contacts[i].get_nickname();
		_phone = this->contacts[i].get_phone();
		_secret = this->contacts[i].get_secret();
		if (_fname.length() > 9)
			_fname = _fname.substr(0, 9) + ".";
		else if (_lname.length() > 9)
			_lname = _lname.substr(0, 9) + ".";
		else if (_nick.length() > 9)
			_nick = _nick.substr(0, 9) + ".";

		std::cout << std::setw(10) << _fname << "|";
		std::cout << std::setw(10) << _lname << "|";
		std::cout << std::setw(10) << _nick << "|" << std::endl;
		i++;
	}

	int x;
	while (true)
	{
		std::cout << std::endl << "Select the contact's index to get more info: ";
		if (!std::getline(std::cin, line))
			break ;
		line = trim(line);

		if (line.length() == 1 && line[0] >= '1' && line[0] <= '8')
    		x = line[0] - '1';
		else
		{
    		std::cout << "Invalid index!" << std::endl;
    		continue;
		}
		if (x >= this->count)
		{
			std::cout << "Contact [" << x + 1 << "/8] not found!" << std::endl;
			continue;
		}

		std::cout << "FirstName: " << contacts[x].get_fname() << std::endl;
		std::cout << "LastName: " << contacts[x].get_lname() << std::endl;
		std::cout << "NickName: " << contacts[x].get_nickname() << std::endl;
		std::cout << "Phone: " << contacts[x].get_phone() << std::endl;
		std::cout << "Secret: " << contacts[x].get_secret() << std::endl;
		break ;
	}
}