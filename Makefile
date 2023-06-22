# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 10:54:53 by svanmeen          #+#    #+#              #
#    Updated: 2023/06/22 14:46:57 by svanmeen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c
SRCSB		=	main_bonus.c
HSRC		=	minitalk.h
OBJS		=	${SRCS:.c=.o}
OBJSB		=	${SRCSB:.c=.o}
DIR_C		= clients/
DIR_S		= servers/
CLIENT_N	= client
SERVER_N	= server


CC			= cc
RM			= rm -f
FLAGS		= -Wall -Wextra -Werror -g3

%.o: %.c	${HSRC}
			${CC} ${FLAGS} -c $< -o $@

all:	${SERVER_N} ${CLIENT_N}

${CLIENT_N}:	${DIR_C}${OBJS}
				make -C libft
				${CC} -o $@ ${DIR_C}${OBJS} -L libft -lft

${SERVER_N}:	${DIR_S}${OBJS}
				make -C libft
				${CC} -o $@ ${DIR_S}${OBJS} -L libft -lft

bonus:	fclean ${SERVER_N}_bonus ${CLIENT_N}_bonus

${SERVER_N}_bonus:	${DIR_S}${OBJSB}
				make -C libft
				${CC} -o ${SERVER_N} ${DIR_S}${OBJSB} -L libft -lft

${CLIENT_N}_bonus:	${DIR_C}${OBJSB}
				make -C libft
				${CC} -o ${CLIENT_N} ${DIR_C}${OBJSB} -L libft -lft

clean:
		${RM} ${DIR_C}${OBJS}
		${RM} ${DIR_S}${OBJS}
		${RM} ${DIR_C}${OBJSB}
		${RM} ${DIR_S}${OBJSB}

fclean:	clean
		${RM} ${SERVER_N}
		${RM} ${CLIENT_N}

re:	fclean all
