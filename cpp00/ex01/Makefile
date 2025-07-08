CC	=	g++

NAME	=	phonebook

CFLAGS	=	-Wall -Wextra -std=c++98

HEADERS	=	inc/PhoneBook.hpp \
			inc/Contact.hpp \
			inc/helper.hpp

SRCS	=	src/Contact.cpp \
			src/PhoneBook.cpp \
			src/helper.cpp \
			src/main.cpp

OBJ_DIR	=	src/obj

OBJS	= $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re