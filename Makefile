#Program name
NAME = philo

#Compiler
CC = cc

#Flags
CFLAGS = -Wall -Wextra -Werror -g

#header
DEPS = philo.h

#Sources
SRC = main.c \
alloc.c \
init.c \
input_check.c \
input_check2.c \
print.c \
routine.c \
threads.c \
time.c \
dead.c

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