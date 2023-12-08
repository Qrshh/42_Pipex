NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror 

INCLUDES = -I./inc -I./libft/inc

LIBFT = Libft/libft.a
LIBFT_DIR = Libft

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = pipex

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES:=.c))
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus