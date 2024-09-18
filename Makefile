NAME =  so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = -I/usr/include -Imlx

GREEN = \033[1;32m
BLUE= \033[1;34m
RED = \033[1;31m
NC = \033[0m

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

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
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS)  $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "\n$(BLUE)=============================================$(NC)\n"
	
$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@echo "libft : $(GREEN)[OK]$(NC)"
	
clean :
	@make clean -C ./libft
	@clear
	@echo "$(RED)========== [ OBJECT DELETED ] ==========$(NC)"
	rm -rf $(OBJ_DIR)
	@echo "clean -C ./libft"
	@echo "$(RED)========================================$(NC)"
	
fclean : clean
	@make fclean -C ./libft
	@clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"
	rm -f $(NAME) 
	@echo "fclean -C ./libft"
	@echo "$(RED)=============================================$(NC)"

re : fclean all

.PHONY : all clean fclean re

