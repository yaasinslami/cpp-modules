/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:26:14 by yslami            #+#    #+#             */
/*   Updated: 2025/07/10 11:39:04 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string const	brain = "HI THIS IS BRAIN";
	std::string const*	stringPTR = &brain;
	std::string const&	stringREF = brain;

	std::cout << "____Memory addresses:\n"
						<< "Address of string:\t\t" << &brain << "\n"
						<< "Address held by stringPTR:\t" << stringPTR << "\n"
						<< "Address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << "____Values:\n"
					<< "value of string:\t\t" << brain << "\n"
					<< "Value pointed to by stringPTR:\t" << *stringPTR << "\n"
					<< "Value pointed to by stringREF:\t" << stringREF << std::endl;
	return 0;
}
