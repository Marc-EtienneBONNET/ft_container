# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonnet <mbonnet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 13:05:15 by mbonnet           #+#    #+#              #
#    Updated: 2022/05/14 08:47:33 by mbonnet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	executable

SRCS			=	srcs/main.cpp\
					srcs/tester_vector.cpp\
					srcs/tester_iterator.cpp\
					srcs/tester_stack.cpp\
					srcs/tester_map.cpp\
					srcs/main_de_test.cpp\

OBJS			=	${addprefix ,${SRCS:.cpp=.o}}

HEAD			=	-I includes/

CC				=	clang++

CFLAGS			=	-std=c++98 -Wall -Wextra -Werror -g

.cpp.o			:
					${CC} ${CFLAGS} ${HEAD}  -c $< -o ${<:.cpp=.o} 

$(NAME)			:	${OBJS}
					${CC} ${CFLAGS} ${OBJS}  -o ${NAME} 

ex 				: $(NAME)
					./$(NAME)
all				:	${NAME}

clean			:
					rm -rf ${OBJS}

fclean			:	clean
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re