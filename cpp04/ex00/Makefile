CC	=	c++

NAME	=	animal

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADERS	=	inc/Animal.hpp \
			inc/Dog.hpp \
			inc/Cat.hpp \
			inc/WrongCat.hpp \
			inc/WrongAnimal.hpp

SRCS	=	src/Animal.cpp \
			src/Dog.cpp \
			src/Cat.cpp \
			src/WrongCat.cpp \
			src/WrongAnimal.cpp \
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