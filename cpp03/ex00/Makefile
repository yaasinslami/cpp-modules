CC		=	c++

NAME	=	ex00

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	ClapTrap.hpp

SRCS	=	ClapTrap.cpp \
			main.cpp

OBJS	=	$(SRCS:.cpp=.o)

RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@$(RM) $(OBJS)

fclean:	clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re