# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/03/01 15:56:21 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADERS = so_long.h

CFLAGS = -Wall -Wextra -Werror

MLXDIR = ./mlx/
MLXLIB = libmlx.dylib
MLX = $(MLXDIR)$(MLXLIB)
FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = $(FTPRINTFDIR)libftprintf.a

SRCS = so_long.c map_read.c free_stuff.c map_build.c open_xpm.c hooks.c

SRCOBJ = $(SRCS:.c=.o)

GREEN = \033[0;32m
RED = \033[0;31m

all: $(NAME) $(FTPRINTFLIB) $(MLX)

$(NAME): $(SRCOBJ) $(FTPRINTFLIB) $(MLX)
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FTPRINTFLIB)
	cp $(MLX) ./
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(FTPRINTFLIB):
	$(MAKE) -C $(FTPRINTFDIR)

$(MLX):
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

.PHONY: all ft_printf mlx clean fclean re
