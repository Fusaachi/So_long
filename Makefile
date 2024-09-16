NAME =  so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Imlx

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)libft.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11 ./libft/libft.a

FILE = main ft_print_line key_hook ft_position ft_init_var ft_check_map mouse_hook ft_collect verif ft_create_map ft_parsing

FILE_DIR = ./
OBJ_DIR = ./obj/

FILES = $(addprefix $(FILE_DIR), $(addsuffix .c, $(FILE)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILE)))

all : $(NAME)

$(OBJ_DIR)%.o: $(FILE_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS)  $(OBJS) $(MLX_FLAGS) -o $(NAME)
	
$(LIBFT):
	@make -C ./libft all
	

clean :
	rm -rf $(OBJ_DIR)
	make -C ./libft clean

fclean : clean
	rm -f $(NAME)
	make -C ./libft fclean

re : fclean all
	make -C ./libft re
	make
	

.PHONY : all clean fclean re

