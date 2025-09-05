#include "Data.hpp"
#include <iostream>

Data::Data( void ) : _id(0), _username("default") {}

Data::Data(int id, std::string username) : _id(id), _username(username) {}

Data::Data(const Data& data) : _id(data._id), _username(data._username)
{}

Data::~Data() {}

Data& Data::operator=(const Data& data)
{
	if (this != &data)
	{
		this->_id = data._id;
		this->_username = data._username;
	}
	return *this;
}

int	Data::getId( void ) const
{
	return this->_id;
}

std::string Data::getUser( void ) const
{
	return this->_username;
}

std::ostream& operator<<(std::ostream& os, const Data& obj)
{
	os << "======== Player id: " << obj.getId() << " ========" << std::endl;
	os << "username: " << obj.getUser() << std::endl;
	os << "=====================================" << std::endl;
	return os;
}

