NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
CC = cc
SOURCES = ft_putnbr.c ft_puthexa.c nonega.c ft_putchar.c ft_putstr.c ft_printflibft.c

OBJECTS = $(SOURCES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar -r $(NAME) $(OBJECTS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re all