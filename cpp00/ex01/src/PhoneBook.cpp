/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 17:06:31 by yslami            #+#    #+#             */
/*   Updated: 2025/07/06 23:02:00 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

static void	printwelcome(void)
{
	// system("clear");
	std::cout << "📞 Welcome to the 80s PhoneBook — Where Awesome Meets Crappy Technology!" << std::endl;
	std::cout << "Type one of the following commands to continue:" << std::endl;
	std::cout << "\t• ADD    → Add a new contact" << std::endl;
	std::cout << "\t• SEARCH → Search and view a contact" << std::endl;
	std::cout << "\t• EXIT   → Exit the program (contacts will be lost!)" << std::endl;
	std::cout << "────────────────────────────────────────────────────────" << std::endl;
}

PhoneBook::PhoneBook(void)
{
	index = 0;
	empty = true;
	printwelcome();
}

PhoneBook::~PhoneBook(void) {
	
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
			return "";  // handle EOF
		line = trim(line);
		if (!line.empty())
			return line;
		std::cout << "❓ Invalid input: field cannot be empty or only whitespace." << std::endl;
	}
}


void	PhoneBook::add(void)
{
	// system("clear");
	std::cout << "📇 Adding a new contact..." << std::endl;

	const std::string prompts[5] = {
		"Enter a first name: ",
		"Enter a last name: ",
		"Enter a nickname: ",
		"Enter a phone number: ",
		"Enter a darkest secret: "
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
		// system("clear");
	}

	std::cout << contacts[index].get_nickname() << " contact added! [" << index + 1 <<  "/8]" << std::endl;
	index = (index + 1) % 8;
	empty = false;
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

	if (empty)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
		return ;
	}
	// system("clear");
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "FirstName" << "|"
			<< std::setw(10) << "LastName" << "|"
			<< std::setw(10) << "NickName" << "|"
			<< std::endl;
	while (i < index)
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
	while (!std::cin.eof())
	{
		std::cout << std::endl << "Select the contact's index to get more info: ";
		if (!std::getline(std::cin, line))
		{
			// system("clear");
			break ;
		}
		line = trim(line);
		int	x = std::atoi(line.c_str());
		x--;
		if (x < 0 || x > 7)
		{
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		if (x >= index)
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
