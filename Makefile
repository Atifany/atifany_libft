# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atifany <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 14:43:00 by atifany           #+#    #+#              #
#    Updated: 2021/10/26 14:43:01 by atifany          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
DEPS = libft.h
NAME = libft.a

_SRC = ft_atoi.c ft_isalpha.c ft_isalnum.c \
       ft_isdigit.c ft_isprint.c ft_strlen.c ft_strncmp.c \
       ft_tolower.c ft_toupper.c ft_isascii.c ft_strchr.c \
       ft_strnstr.c ft_strlcpy.c ft_strlcat.c ft_memset.c \
       ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c \
       ft_memmove.c ft_calloc.c ft_strdup.c ft_substr.c \
       ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c \
       ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
       ft_putendl_fd.c ft_putnbr_fd.c ft_strrchr.c
_SRCB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

OBJB = $(_SRCB:%.c=%.o)
OBJ = $(_SRC:%.c=%.o)

all: $(NAME)

%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
		$(AR) $(NAME) $(OBJ)

bonus:
		@make all OBJ="$(OBJ) $(OBJB)"

clean:
		rm -f $(OBJ) $(OBJB)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean bonus all
