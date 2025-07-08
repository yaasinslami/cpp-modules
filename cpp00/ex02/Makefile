CC	=	g++

NAME	=	banksystem

CFLAGS	=	-Wall -Wextra -std=c++98

HEADER	=	Account.hpp

SRCS	=	Account.cpp \
			tests.cpp

OBJS	= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re