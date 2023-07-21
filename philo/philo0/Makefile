NAME = philo

CFLAGS = -Wall -Werror -Wextra -pthread -I includes

UTILS = ${addprefix utils/, util0.c util1.c ft_atoi.c}

SRCS = ${addprefix source/, pp.c ${UTILS}}

OBJS = ${SRCS:c=o}

%.o : %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} Makefile
	@${CC} ${CFLAGS} ${OBJS} -o $@

all : ${NAME}

clean :
	@${RM} ${OBJS}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re