OBJ = \
		Bureaucrat.o \
		main.o \

all: bureaucrat

bureaucrat: $(OBJ)
	c++ $^ -o $@

%.o: %.cpp
	c++ -std=c++98 -Wall -Werror -Wextra -c $^ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f bureaucrat

re: fclean all

.PHONY: clean fclean re