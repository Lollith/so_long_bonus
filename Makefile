# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agouet <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 11:45:07 by agouet            #+#    #+#              #
#    Updated: 2022/04/05 11:52:13 by agouet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS_PATH	= ./sources/

GNL_PATH	= ./gnl/

SRCS		= $(addprefix $(SRCS_PATH), so_long.c  render.c  hook.c errors.c \
			 	 window.c map.c game.c move.c checks_map.c utils.c img.c \
				render_anim.c)\
			  $(addprefix $(GNL_PATH), get_next_line.c get_next_line_utils.c)

OBJS		= $(SRCS:.c=.o)

DEPS		= $(SRCS:.c=.d)

CC			= cc

CFLAGS		= -MMD -Wall -Wextra -Werror -g -O3

LDFLAGS		= -lmlx_Linux -lXext -lX11 -lm  -lz

LIB			= -L ./mlx_linux -L /usr/lib

INC			= -I ./includes  -I /usr/include  -I ./mlx_linux


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB) $(LDFLAGS)

%.o			:%.c
			$(CC) $(CFLAGS) -c $< -o $@ $(INC)
clean:	
			rm -f $(OBJS) $(DEPS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all re clean fclean 

-include $(DEPS)
