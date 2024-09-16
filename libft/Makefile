# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgiroux <pgiroux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 17:00:17 by pgiroux           #+#    #+#              #
#    Updated: 2024/09/12 12:13:08 by pgiroux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g


FILE =	ft_putchar ft_putstr_fd ft_split ft_strjoin ft_strlcpy ft_strlen ft_strjoin_gnl get_next_line ft_init ft_clearbuffer ft_check ft_strncmp ft_free ft_itoa

FILE_DIR = ./src/
OBJ_DIR = ./obj/

FILES = $(addprefix $(FILE_DIR), $(addsuffix .c, $(FILE)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))

all: $(NAME)

$(OBJ_DIR)%.o: $(FILE_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $<
	

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm  -rf $(OBJ_DIR)
	
fclean : clean
	rm -f $(NAME)

re : fclean all
	make

.PHONY : all clean fclean re
