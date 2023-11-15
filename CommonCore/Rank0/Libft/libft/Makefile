SRCS = 	ft_isdigit.c ft_toupper.c ft_tolower.c ft_isalpha.c ft_isalnum.c\
	ft_isprint.c ft_isascii.c ft_strlen.c ft_strncmp.c ft_strdup.c\
	ft_strchr.c ft_strrchr.c ft_strnstr.c ft_memset.c ft_memmove.c\
	ft_memcpy.c ft_memcmp.c ft_memchr.c ft_bzero.c ft_atoi.c\
	ft_calloc.c ft_strlcpy.c ft_strlcat.c ft_putchar_fd.c\
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c\
	ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c

#BONUS_S =

OBJS =	$(SRCS:.c=.o)

OBJS_BONUS =	${BONUS_S:.c=.o}

NAME =	libft.a

CC =	cc
RM =	rm -f
COMP =	ar rcs

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(COMP) $(NAME) $(OBJS)

all:	$(NAME)

bonus:	$(NAME) $(OBJS_BONUS)
	$(COMP) $(NAME) $(OBJS_BONUS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re

### delete this before submit the project
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
