# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 19:21:10 by adrmarqu          #+#    #+#              #
#    Updated: 2024/04/27 12:32:11 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAMEB = pipex_bonus

SRC = $(wildcard src/main/*.c)
OBJ = $(SRC:.c=.o)

SRCB = $(wildcard src/bonus/*.c)
OBJB = $(SRCB:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

RM = rm -rf

all: $(NAME)

bonus: $(NAMEB)

$(NAME): $(OBJ)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

$(NAMEB): $(OBJB)
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) $^ -o $@ -Llibft -lft

%.o: %.c include/pipex.h include/color.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C ./libft clean
	@$(RM) $(OBJ) $(OBJB)
	@echo "clean of pipex"

fclean:
	@$(MAKE) -C ./libft fclean
	@$(RM) $(OBJ) $(OBJB)
	@$(RM) $(NAME) $(NAMEB)
	@echo "fclean of pipex"

re: fclean all bonus

.PHONY: all clean fclean re libft bonus

