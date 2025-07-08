/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 16:47:36 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 17:52:01 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/helper.hpp"

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

void	printwelcome(void)
{
	std::cout << "📞 Welcome to the 80s PhoneBook — Where Awesome Meets Crappy Technology!" << std::endl;
	std::cout << "🕹️ Type one of the following commands to continue:" << std::endl;
	std::cout << "\t• ADD    → Add a new contact" << std::endl;
	std::cout << "\t• SEARCH → Search and view a contact" << std::endl;
	std::cout << "\t• EXIT   → Exit the program (contacts will be lost!)" << std::endl;
	std::cout << "────────────────────────────────────────────────────────" << std::endl;
}
