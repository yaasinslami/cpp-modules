CC	=	c++

NAME	=	weapons

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADERS	=	inc/HumanA.hpp \
			inc/HumanB.hpp \
			inc/Weapon.hpp

SRCS	=	src/HumanA.cpp \
			src/HumanB.cpp \
			src/Weapon.cpp \
			src/main.cpp

OBJ_DIR	=	src/obj

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