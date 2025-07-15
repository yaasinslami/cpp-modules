/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslami <yslami@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:27:18 by yslami            #+#    #+#             */
/*   Updated: 2025/07/15 14:36:40 by yslami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1,
	const std::string& s2) : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::~FileReplacer( void ) { }

static bool isDirectory(const std::string& path)
{
	struct stat s;
	if (stat(path.c_str(), &s) == 0)
		return S_ISDIR(s.st_mode);
	else
		return false;
}

bool FileReplacer::_isReadableFile(std::ifstream &file) const
{
	if (isDirectory(this->_filename))
	{
		std::cout << "Error: '" << this->_filename << "' is a directory." << std::endl;
		return false;
	}

	char buffer[256];
	file.read(buffer, sizeof(buffer));
	std::streamsize bytesRead = file.gcount();

	if (file.fail() && !file.eof()) {
    	std::cout << "Read failed (bad file?)\n";
    	return false;
	}

	if (bytesRead == 0)
	{
		file.clear();
		file.seekg(0);
		return true;
	}

	for (std::streamsize i = 0; i < bytesRead; ++i)
	{
		unsigned char c = static_cast<unsigned char>(buffer[i]);
		if (!std::isprint(c) && c != '\n' && c != '\r' && c != '\t')
		{
			std::cout << "Error: '" << this->_filename << "' appears to be a binary file." << std::endl;
			return false;
		}
	}

	file.clear();
	file.seekg(0);
	return true;
}

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
