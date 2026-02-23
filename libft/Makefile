# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:50:10 by alago-ga          #+#    #+#              #
#    Updated: 2025/10/03 13:50:40 by alago-ga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRC = \
src/ft_atoi.c \
src/ft_bzero.c \
src/ft_calloc.c \
src/ft_isalnum.c \
src/ft_isalpha.c \
src/ft_isascii.c \
src/ft_isdigit.c \
src/ft_isprint.c \
src/ft_itoa.c \
src/ft_lstadd_back_bonus.c \
src/ft_lstadd_front_bonus.c \
src/ft_lstclear_bonus.c \
src/ft_lstdelone_bonus.c \
src/ft_lstiter_bonus.c \
src/ft_lstlast_bonus.c \
src/ft_lstnew_bonus.c \
src/ft_lstsize_bonus.c \
src/ft_memchr.c \
src/ft_memcmp.c \
src/ft_memcpy.c \
src/ft_memmove.c \
src/ft_memset.c \
src/ft_putchar_fd.c \
src/ft_putendl_fd.c \
src/ft_putnbr_fd.c \
src/ft_putstr_fd.c \
src/ft_split.c \
src/ft_strchr.c \
src/ft_strdup.c \
src/ft_striteri.c \
src/ft_strjoin.c \
src/ft_strlcat.c \
src/ft_strlcpy.c \
src/ft_strlen.c \
src/ft_strmapi.c \
src/ft_strncmp.c \
src/ft_strnstr.c \
src/ft_strrchr.c \
src/ft_strtrim.c \
src/ft_substr.c \
src/ft_tolower.c \
src/ft_toupper.c \
ft_printf/ft_printf.c \
ft_printf/ft_putchar.c \
ft_printf/ft_puthex.c \
ft_printf/ft_putnbr_u.c \
ft_printf/ft_putnbr.c \
ft_printf/ft_putptr.c \
ft_printf/ft_putstr.c \
get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
