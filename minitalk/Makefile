# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anepali <anepali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 12:18:57 by anepali           #+#    #+#              #
#    Updated: 2022/12/30 14:26:05 by anepali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: comp_libft Server Client

$(NAME): comp_libft Server Client

LIBFT	= cd libft && make

LIBFT_OBJ = libft/libft.a

Server_src = server.c
Client_src = client.c

Server_OBJ = $(Server_src:.c=.o)
Client_OBJ = $(Client_src:.c=.o)

comp_libft:
	@$(LIBFT)
	
Server: $(Server_OBJ)
	@cc -Wall -Werror -Wextra $(Server_OBJ) $(LIBFT_OBJ) -o server

Client: $(Client_OBJ)
	@cc -Wall -Werror -Wextra $(Client_OBJ) $(LIBFT_OBJ) -o client

.c.o:
	@cc -Wall -Werror -Wextra -I include -c $< -o ${<:.c=.o}
	
fclean: clean
	rm -f server client
	cd libft && make fclean
	
clean:
	/bin/rm -f *.o
	cd libft && make clean


re:	fclean all