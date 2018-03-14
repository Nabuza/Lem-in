#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 17:29:00 by nagaloul          #+#    #+#              #
#    Updated: 2017/05/11 16:38:20 by nagaloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
GCC = gcc -c -Wall -Wextra -Werror
SRC =	lem.c \
		ft_pars.c \
		ft_create_elem.c \
		ft_push_back.c \
		ft_check.c \
		ft_recover.c \
		ft_list_clear.c \
		ft_samelink.c \
		ft_way.c \
		ft_freestrings.c \
		ft_oneone.c

OBJ = $(addprefix src/,$(SRC:.c=.o))

all: $(NAME)


$(NAME): $(OBJ)
		@make -C libft/
		@gcc $(OBJ) -o $(NAME) -L libft -lft

clean:
		make clean -C libft
		@rm -f $(OBJ)

fclean: clean
		make fclean -C libft
		@rm -f $(NAME)

re: fclean all
