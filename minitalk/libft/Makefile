# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anepali <anepali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:00:35 by anepali           #+#    #+#              #
#    Updated: 2022/12/30 14:29:46 by anepali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c \
		ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c ft_strtrim.c \
		ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c ft_substr.c \
		ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c \
		ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c \
		ft_printf.c ft_printf_itoa.c ft_printf_hex.c ft_printf_putstr.c ft_printf_putchar.c \
		ft_printf_putpointer.c ft_printf_unsigndec.c

BONUS_SRC =	ft_lstnew.c ft_lstadd_front.c  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c
			
OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJ)
	@cc -Wall -Werror -Wextra -c $(SRC)
	@ar -rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	cc -Wall -Werror -Wextra -c $(BONUS_SRC)
	ar -rcs $(NAME) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)
clean:
	/bin/rm -f *.o

re:	fclean all