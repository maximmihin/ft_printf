NAME = libftprintf.a

HEADER = ft_printf.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADER)

SRC = ft_hex.c	ft_putnbr_pf.c	ft_putstr_pf.c	ft_printf.c

OBJ = $(SRC:%.c= %.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o	: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJ)

fclean	:	clean
	@$(RM) $(NAME)

re	:	fclean all