NAME = pipex

LIBFT = Libft/libft.a

SRCS =	pipex.c \
	pipex_utils.c \

OBJS = ${SRCS:.c=.o}

SRCBONUS = pipex_bonus.c \
	pipex_utils.c \

OBJSBONUS = ${SRCBONUS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
	
all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

bonus : $(OBJSBONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C Libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJSBONUS)
	make clean -C Libft

fclean : clean
	$(RM) $(NAME) $(NAMEBNS)
	make fclean -C Libft

re : fclean all

.PHONY: all, clean, fclean, re, bonus
