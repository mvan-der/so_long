# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/02/04 11:04:40 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

MLXDIR = ./mlx/
MLXLIB = libmlx.dylib
SRCS = so_long.c

SRCOBJ = $(SRCS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(SRCOBJ) $(MLXLIB)
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp $(MLXDIR)$(MLXLIB) ./
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(MLXLIB): $(SRCOBJ)
	$(MAKE) -C $(MLXDIR)

clean:
	rm -f $(SRCOBJ)
	$(MAKE) -C $(MLXDIR) $@

fclean: clean
	rm -f $(NAME)
	rm -f $(MLXLIB)

re: fclean all

.PHONY: all mlx clean fclean re
