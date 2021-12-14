# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vseel <vseel@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 15:41:45 by vseel             #+#    #+#              #
#    Updated: 2021/11/08 10:52:40 by vseel            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_pre_putnbr_d_i.c ft_pre_putnbr_u.c \
			ft_pre_putnbr_x.c ft_pre_putptr.c ft_pre_putstr_putchar.c \
			ft_put_nbr_ptr_charntimes.c ft_put_char_str_numlens.c 
HEAD	=	ft_printf.h
OBJS	=	$(patsubst %.c, %.o, $(SRCS))

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

ARLIB	=	ar rcs
RM		=	rm -f

.PHONY:		all clean fclean re bonus

%.o : %.c	$(HEAD)
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEAD)
			$(ARLIB) $(NAME) $?

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		all