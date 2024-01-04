SRCS =	ft_printf.c pf_putchar.c pf_putstr.c pf_putptr.c \
	pf_putnbr.c pf_put_uint.c pf_puthexadec.c \
	pf_strlen.c pf_numlen.c

OBJS = 	$(SRCS:.c=.o)

NAME =	libftprintf.a

CC =	cc
RM  =	rm -rf
COMP =	ar rcs

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
		$(COMP) $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
