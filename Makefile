#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/04/15 00:42:52 by hponcet           #+#    #+#             *#
#*   Updated: 2016/05/11 14:23:13 by hponcet          ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = select

CC = gcc

CFLAGS = -Wall -Wall -Wextra

SRC =	ft_bar.c \
		ft_char.c \
		ft_display.c \
		ft_key.c \
		ft_link.c \
		ft_signal.c \
		ft_term.c \
		main.c

OBJECTS = $(addprefix $(SRCS), $(SRC:.c=.o))

LIBFT = ./libft/

LIB = libft.a

SRCS = ./srcs/

INC = ./includes/

LIB_FILE = $(addprefix $(LIBFT), $(LIB))

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB_FILE)
	-@$(CC) $(CFLAGS) $(OBJECTS) -L $(LIBFT) -ltermcap -lft -I$(INC) -o $(NAME)
	@echo "Select ready to use !"

$(LIB_FILE):
	@echo "Waiting, libft is in compilation..."
	-@make proper -C $(LIBFT)

%.o: %.c
	-@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean :
	-@rm -rf $(SRCS)*.o

fclean: clean libfclean
	-@rm -rf $(NAME)
	@echo "Binarie deleted."
	-@make fclean -C $(LIBFT)
	@echo "Libft cleaned."

libfclean:
	-@make fclean -C $(LIBFT)

libclean :
	-@make clean -C $(LIBFT)

re: libfclean fclean all

proper: all libfclean clean

