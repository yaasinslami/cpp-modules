CC	=	c++

NAME	=	materia

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADERS	=	inc/AMateria.hpp \
			inc/Ice.hpp \
			inc/Cure.hpp \
			inc/ICharacter.hpp \
			inc/Character.hpp \
			inc/IMateriaSource.hpp \
			inc/MateriaSource.hpp

SRCS	=	src/AMateria.cpp \
			src/Ice.cpp \
			src/Cure.cpp \
			src/ICharacter.cpp \
			src/Character.cpp \
			src/IMateriaSource.cpp \
			src/MateriaSource.cpp \
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