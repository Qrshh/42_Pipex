CC = cc

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = \
	file/ft_putchar_fd.c \
	file/ft_putendl_fd.c \
	file/ft_putnbr_fd.c \
	file/ft_putstr_fd.c \
	\
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	mem/ft_memset.c \
	\
	nbr/ft_atoi.c \
	nbr/ft_itoa.c \
	\
	others/ft_isalnum.c \
	others/ft_isalpha.c \
	others/ft_isascii.c \
	others/ft_isdigit.c \
	others/ft_isprint.c \
	\
	str/ft_split.c \
	str/ft_strchr.c \
	str/ft_strcmp.c \
	str/ft_strdup.c \
	str/ft_striteri.c \
	str/ft_strjoin.c \
	str/ft_strlcat.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_strmapi.c \
	str/ft_strncmp.c \
	str/ft_strndup.c \
	str/ft_strnstr.c \
	str/ft_strrchr.c \
	str/ft_strtrim.c \
	str/ft_substr.c \
	str/ft_tolower.c \
	str/ft_toupper.c \
	\
	printf/ft_printf.c \
	printf/ft_printf_utils.c \
	\
	gnl/get_next_line.c \
	gnl/get_next_line_utils.c \
	\

SRCS_BONUS = \
	lst/ft_lstadd_back.c \
	lst/ft_lstadd_front.c \
	lst/ft_lstclear.c \
	lst/ft_lstdelone.c \
	lst/ft_lstiter.c \
	lst/ft_lstlast.c \
	lst/ft_lstmap.c \
	lst/ft_lstnew.c \
	lst/ft_lstsize.c \
		
OBJS = ${SRCS:.c=.o}

BONUS = ${SRCS_BONUS:.c=.o}

RM = rm -rf

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}
		
all : ${NAME}

$(NAME) : ${OBJS}
	ar rcs $(NAME) $(OBJS)

bonus : ${OBJS} $(BONUS)
	ar rcs $(NAME) $(OBJS) ${BONUS}

clean :
	$(RM) $(OBJS) $(BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all, clean, fclean, re
