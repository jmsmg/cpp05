CC = c++
FLAG = -Wall -Wextra -Werror -std=c++98
NAME = a.out
OBJS = $(SRCS:.cpp=.o)
SRCS = main.cpp Bureaucrat.cpp \
		Form/AForm.cpp \
		Form/ShrubberyCreationForm.cpp \
		Form/RobotomyRequestForm.cpp \
		Form/PresidentialPardonForm.cpp

%.o: %.cpp
	$(CC) $(FLAG) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re