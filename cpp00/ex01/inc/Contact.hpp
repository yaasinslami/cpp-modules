/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:28:54 by yslami            #+#    #+#             */
/*   Updated: 2025/07/08 16:02:23 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string	fname;
		std::string	lname;
		std::string	nickname;
		std::string	phone;
		std::string	secret;
	public:
		Contact(void);
		~Contact(void);
		/* getters */
		std::string	get_fname(void) const;
		std::string	get_lname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone(void) const;
		std::string	get_secret(void) const;
		/* setters */
		void		set_fname(const std::string& _fname);
		void		set_lname(const std::string& _lname);
		void		set_nickname(const std::string& _nickname);
		void		set_phone(const std::string& _phone);
		void		set_secret(const std::string& _secret);
};

#endif