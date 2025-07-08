/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:28:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 14:05:43 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main()
{
	PhoneBook	book;
	std::string	name;

	while (true)
	{
		std::cout << "Enter a command > ";
		if (!std::getline(std::cin, name))
        {
            std::cout << std::endl;
            break ;
        }

		name = trim(name);

		if (name == "ADD")
			book.add();
		else if (name == "SEARCH")
			book.search();
		else if (name == "EXIT")
			break ;
		else
		{
			std:: cout << "❓ Unknown command. Please use one of the following:" << std::endl;
			std::cout << "ADD | SEARCH | EXIT" << std::endl;
		}
	}
	return 0;

}
