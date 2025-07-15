/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:21:15 by yslami            #+#    #+#             */
/*   Updated: 2025/07/15 14:05:59 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <fstream>
#include <iostream>
#include <sys/stat.h>

class FileReplacer 
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;

		bool 		_isReadableFile(std::ifstream &file) const;
		bool 		_readFile(std::string &content) const;
		bool 		_writeFile(const std::string& content) const;
		std::string _replaceAll(const std::string& content) const;

	public:
		FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
		~FileReplacer( void );

		bool process( void ) const;
};

#endif
