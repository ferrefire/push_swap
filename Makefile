CC=cc
CFLAGS= -Wall -Wextra -Werror
LFLAGS= -Llibft -lft
SRC= push_swap.c operations.c utilities.c
OBJ=$(SRC:%.c=%.o)
NAME=push_swap

$(NAME): $(SRC) push_swap.h
	$(CC) $(CFLAGS) -c $(SRC)
	cd libft && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)
	cd libft && $(MAKE) clean

fclean: clean
	rm -f $(NAME)
	cd libft && $(MAKE) fclean

all: $(NAME)

re: fclean all