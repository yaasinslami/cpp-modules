/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:28:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/06 21:00:15 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main() 
{
	PhoneBook	book;
	std::string	name;

	while (name != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, name);
		name = trim(name);
		if (name == "ADD")
			book.add();
		else if (name == "SEARCH")
			book.search();
		else if (name != "EXIT" && !std::cin.eof())
		{
			std:: cout << "❓ Unknown command. Please use one of the following:" << std::endl;
			std::cout << "ADD | SEARCH | EXIT" << std::endl;
		}
		if (name == "EXIT" || std::cin.eof())
		{
			std::cout << std::endl;
			break ;
		}
	}
	return 0;

}
