/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:27:18 by yslami            #+#    #+#             */
/*   Updated: 2025/07/11 22:52:42 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FileReplacer.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sys/stat.h>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1,
	const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::~FileReplacer( void ) { }

// bool	FileReplacer::_readFile(std::string &content) const
// {
// 	std::string line;

// 	std::ifstream	inputFile(_filename.c_str());
// 	if (!inputFile)
// 	{
// 		std::cerr << "Error: failed to open input file: " << _filename << std::endl;
// 		return false;
// 	}

// 	while (std::getline(inputFile, line))
// 	{
// 		content += line;
// 		content += '\n';
// 	}

// 	inputFile.close();

// 	if (!content.empty() && content[content.length() - 1] == '\n')
// 		content.erase(content.length() - 1, 1);
// 	return true;
// }

bool FileReplacer::_readFile(std::string &content) const
{
	std::ifstream inputFile(this->_filename.c_str());

	// This check alone is not enough:
	if (!inputFile || inputFile.fail())
	{
		std::cerr << "Error: failed to open file '" << _filename << "'." << std::endl;
		return false;
	}

	// Now try to read just one character
	char test;
	inputFile.get(test);
	if (inputFile.eof()) {
		// It's an empty file — acceptable
		inputFile.clear();
		inputFile.seekg(0); // reset to start
	}
	else if (inputFile.fail()) {
		// Likely a directory or unreadable file
		std::cerr << "Error: '" << _filename << "' is not a readable file." << std::endl;
		return false;
	}
	else {
		inputFile.clear();
		inputFile.seekg(0); // reset to start
	}

	// Proceed with full read
	std::string line;
	content.clear();
	while (std::getline(inputFile, line))
	{
		content += line;
		content += '\n';
	}
	inputFile.close();

	// Optional: remove trailing newline
	if (!content.empty() && content[content.length() - 1] == '\n')
		content.erase(content.length() - 1, 1);

	return true;
}

bool	FileReplacer::_writeFile(const std::string &line) const
{
	std::ofstream	outputFile((_filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << "Error: failed to create output file: " << _filename << ".replace" << std::endl;
		return false;
	}

	outputFile << line;
	if (!outputFile.good())
	{
		std::cerr << "Error: failed to write to output file." << std::endl;
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
