CFLAGS		:= -Wall -Wextra -Werror
NAME		:= libft.a
SRCS		:= ${wildcard srcs/*/*.c}
BONUS		:= ${wildcard bonus/*.c}
OBJS		:= ${SRCS:.c=.o}
BONUS_OBJS	:= ${BONUS:.c=.o}
INCS		:= -I includes

%.o		: %.c
	gcc ${INCS} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	: ${OBJS}
	ar -rc ${NAME} ${OBJS}

all		: ${NAME}

clean	:
	rm -f ${OBJS}
	rm -f ${BONUS_OBJS}

fclean	: clean
	rm -f ${NAME}
	rm -f a.out
	rm -f libft.so

re		: fclean all

bonus	: ${OBJS} ${BONUS_OBJS}
	ar -rc ${NAME} ${OBJS} ${BONUS_OBJS}

so:
	$(CC) $(INCS) -nostartfiles -fPIC $(CFLAGS) $(SRCS) ${BONUS}
	gcc -nostartfiles -shared -o libft.so $(OBJS) ${BONUS_OBJS}
