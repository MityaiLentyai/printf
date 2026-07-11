SRC = 	ft_printf.c \


OBJ = $(SRC:.c=.o)
CC = gcc

CFLAGS += -Wall -Werror -Wextra

LIBFT = libft/libft.a

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@ ar -rcs $(NAME) $(OBJ)

$(LIBFT): 
	@ make -C libft

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
