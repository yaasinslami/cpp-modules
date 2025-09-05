#ifndef DATA_HPP
#define DATA_HPP

#include <string>

struct Data
{
	public:
		Data( void );
		Data(int id, std::string username);
		Data(const Data& other);
		~Data();
		Data& operator=(const Data& other);

		int	getId( void ) const;
		std::string	getUser( void ) const;

	private:
		int			_id;
		std::string _username;
};

std::ostream&	operator<<(std::ostream& os, const Data& obj);

#endif

