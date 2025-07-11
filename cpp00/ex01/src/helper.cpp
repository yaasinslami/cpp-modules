/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:47:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/09 18:48:53 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/helper.hpp"

std::string get_input(const std::string& prompt)
{
	std::string line;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, line))
			return "";

		line = trim(line);
		if (!is_printable(line))
		{
			std::cout << "❌ Invalid characters detected." << std::endl;
			continue;
		}
		if (!line.empty())
			return line;
		std::cout << "❓ Invalid input: field cannot be empty or only whitespace." << std::endl;
	}
}

std::string trim(const std::string& str) 
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && std::isspace(str[start]))
        start++;

    while (end > start && std::isspace(str[end - 1]))
        end--;

    return str.substr(start, end - start);
}

bool	is_printable(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
		if (!std::isprint(str[i]))
			return false;
	}
	return true;
}

void	printwelcome(void)
{
	std::cout << "📞 Welcome to the 80s PhoneBook — Where Awesome Meets Crappy Technology!" << std::endl;
	std::cout << "🕹️ Type one of the following commands to continue:" << std::endl;
	std::cout << "\t• ADD    → Add a new contact" << std::endl;
	std::cout << "\t• SEARCH → Search and view a contact" << std::endl;
	std::cout << "\t• EXIT   → Exit the program (contacts will be lost!)" << std::endl;
	std::cout << "────────────────────────────────────────────────────────" << std::endl;
}
