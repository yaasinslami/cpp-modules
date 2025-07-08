
NAME		=	megaphone
CC			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98

SRC			=	megaphone.cpp
OBJ			= $(SRC:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $@

%.o:		%.cpp
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJ)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re