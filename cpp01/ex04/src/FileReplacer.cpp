/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:27:18 by yslami            #+#    #+#             */
/*   Updated: 2025/07/12 14:59:32 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>
#include <string>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1,
	const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::~FileReplacer( void ) { }

bool FileReplacer::_readFile(std::string &content) const
{
	std::ifstream inputFile(this->_filename.c_str());
	if (!inputFile)
	{
		std::cout << "Error: failed to open input file: " << this->_filename << std::endl;
		return false;
	}

	if (!this->_isReadableFile(inputFile))
		return false;

	content.clear();
	char c;

	while (inputFile.get(c))
		content += c;

	inputFile.close();
	return true;
}

bool	FileReplacer::_writeFile(const std::string &line) const
{
	std::ofstream	outputFile((_filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cout << "Error: failed to create output file: " << _filename << ".replace" << std::endl;
		return false;
	}

	outputFile << line;
	if (!outputFile.good())
	{
		std::cout << "Error: failed to write to output file." << std::endl;
		return false;
	}

	outputFile.close();

	return true;
}

std::string FileReplacer::_replaceAll(const std::string& content) const
{
	std::string	result;
	size_t		pos = 0, found;

	while ((found = content.find(this->_s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += this->_s2;
		pos = found + this->_s1.length();
	}
	result += content.substr(pos);

	return result;
}

bool	FileReplacer::process( void ) const
{
	std::string content;

	if (!this->_readFile(content))
		return false;

	std::string replaced = this->_replaceAll(content);

	if (!this->_writeFile(replaced))
		return false;
	
	return true;
}

bool	FileReplacer::_isReadableFile(std::ifstream &file) const
{
	char test;
	file.get(test);

	if (file.eof())
	{
		file.clear();
		file.seekg(0);
		return true;
	}
	else if (file.fail())
	{
		file.clear();
		std::cout << "Error: '" << this->_filename << "' is not a readable text file." << std::endl;
		return false;
	}
	else
	{
		file.clear();
		file.seekg(0);
		return true;
	}
}
