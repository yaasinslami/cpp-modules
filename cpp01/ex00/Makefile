CC		=	c++
NAME	=	zombie
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	Zombie.hpp

SRCS	=	newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp \
			main.cpp

OBJ_DIR	=	obj
OBJS	=	$(SRCS:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re