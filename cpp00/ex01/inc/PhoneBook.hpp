/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:28:44 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 16:03:25 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "helper.hpp"
# include <iomanip>


class PhoneBook {
	private:
		Contact	contacts[8];
		int		index;
		bool	empty;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
};

#endif