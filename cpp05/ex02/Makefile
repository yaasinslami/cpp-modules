CC	=	c++

NAME	=	ExecForm

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

HEADER	=	inc/Bureaucrat.hpp \
			inc/AForm.hpp \
			inc/ShrubberyCreationForm.hpp \
			inc/RobotomyRequestForm.hpp \
			inc/PresidentialPardonForm.hpp

			
SRCS	=	src/Bureaucrat.cpp \
			src/AForm.cpp \
			src/ShrubberyCreationForm.cpp \
			src/RobotomyRequestForm.cpp \
			src/PresidentialPardonForm.cpp \
			src/main.cpp

OBJ_DIR	=	obj

OBJS	= $(SRCS:src/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinc $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: src/%.cpp $(HEADER)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinc -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re