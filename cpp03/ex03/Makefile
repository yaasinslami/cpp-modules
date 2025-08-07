CC	=	c++

NAME	=	ex02

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADERS	=	inc/ClapTrap.hpp \
			inc/ScavTrap.hpp \
			inc/FragTrap.hpp

SRCS	=	src/ClapTrap.cpp \
			src/ScavTrap.cpp \
			src/FragTrap.cpp \
			src/main.cpp

OBJ_DIR	=	obj

OBJS	= $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinc $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re