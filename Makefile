# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/02/15 14:39:29 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADERS = so_long.h

CFLAGS = -Wall -Wextra -Werror

MLXDIR = ./mlx/
MLXLIB = libmlx.dylib
FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = libftprintf.a

SRCS = so_long.c map_read.c free_stuff.c

SRCOBJ = $(SRCS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME)

$(NAME): $(SRCOBJ) $(FTPRINTFLIB) $(MLXLIB)
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FTPRINTFDIR)$(FTPRINTFLIB)
	cp $(MLXDIR)$(MLXLIB) ./
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(FTPRINTFLIB): $(SRCOBJ)
	$(MAKE) -C $(FTPRINTFDIR)

$(MLXLIB): $(SRCOBJ)
	$(MAKE) -C $(MLXDIR)

clean:
	rm -f $(SRCOBJ)
	$(MAKE) -C $(MLXDIR) $@
	$(MAKE) -C $(FTPRINTFDIR) $@

fclean: clean
	rm -f $(NAME)
	rm -f $(MLXLIB)
	$(MAKE) -C $(FTPRINTFDIR) $@

re: fclean all

.PHONY: all mlx clean fclean re
