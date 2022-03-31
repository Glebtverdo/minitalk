NAME1 = client
NAME2 = server

LIBFT = ./libft/ft_isalpha.c ./libft/ft_isdigit.c ./libft/ft_isalnum.c ./libft/ft_isascii.c ./libft/ft_isprint.c \
./libft/ft_strlen.c ./libft/ft_memset.c ./libft/ft_bzero.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_strlcpy.c \
./libft/ft_strlcat.c ./libft/ft_toupper.c ./libft/ft_tolower.c ./libft/ft_strchr.c ./libft/ft_strrchr.c ./libft/ft_strncmp.c \
./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_strnstr.c ./libft/ft_atoi.c ./libft/ft_calloc.c ./libft/ft_strdup.c \
./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strtrim.c ./libft/ft_split.c ./libft/ft_itoa.c ./libft/ft_strmapi.c \
./libft/ft_striteri.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_putendl_fd.c \
./libft/ft_lstnew.c ./libft/ft_lstadd_front.c ./libft/ft_lstsize.c ./libft/ft_lstlast.c \
./libft/ft_lstadd_back.c ./libft/ft_lstdelone.c ./libft/ft_lstiter.c \
./libft/ft_putnbr_fd.c
CLIENT = client.c error.c
SERVER = server.c

OBJS_C = ${CLIENT:.c=.o}
DEPS_C = ${CLIENT:.c=.d}
OBJS_S = ${SERVER:.c=.o}
DEPS_S = ${SERVER:.c=.d}
OBJS_L = ${LIBFT:.c=.o}
DEPS_L = ${LIBFT:.c=.d}
CC   = gcc -Wall -Wextra -Werror -MMD

all:  $(NAME1) $(NAME2)

-include $(DEPS_C) $(DEPS_L) $(DEPS_S)

.c.o :
	$(CC) -c $< -o ${<:.c=.o} -I.

$(NAME1): ${OBJS_C} ${OBJS_L} Makefile
	$(CC) ${OBJS_C} ${OBJS_L} -o $(NAME1)

$(NAME2): ${OBJS_L} ${OBJS_S} Makefile
	$(CC) ${OBJS_S} ${OBJS_L} -o $(NAME2) 

bonus: $(NAME1) $(NAME2)

clean:
	rm -f ${OBJS_C} ${OBJS_L} ${OBJS_S}
	rm -f ${DEPS_C} ${DEPS_L} ${DEPS_S}

fclean: clean
	rm -f $(NAME1) $(NAME2)

re :  fclean all

.PHONY:  all clean fclean re .c.o bonus