#Program name
NAME = philo

#Compiler
CC = cc

#Flags
CFLAGS = -Wall -Wextra -Werror -g

#header
DEPS = philo.h

#Sources
SRC = main.c print.c parse.c 

#Objects
OBJ = $(SRC:.c=.o)

#Remove
RM = rm -f

all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Compiling philo..."
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "philo ready".

clean:
	@echo "Removing .o object files..."
	$(RM) $(OBJ)

fclean: clean
	@echo "Removing philo..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re