# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/03/14 14:13:05 by mvan-der      ########   odam.nl          #
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

SRCS = srcs/so_long.c srcs/gen_utils.c srcs/image_build.c srcs/key_events.c srcs/key_hooks.c srcs/map_build.c srcs/map_check.c

SRCOBJ = $(SRCS:.c=.o)

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

all: $(NAME) $(FTPRINTFLIB) $(MLX)

$(NAME): $(SRCOBJ) $(FTPRINTFLIB) $(MLX)
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FTPRINTFLIB)
	cp $(MLX) ./
	@echo "${GRN}[$(NAME)]${RST} done"
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(FTPRINTFLIB):
	$(MAKE) -C $(FTPRINTFDIR)
	@echo "${GRN}[FT_PRINTF + LIBFT]${RST} done"

$(MLX):
	$(MAKE) -C $(MLXDIR)
	@echo "${GRN}[MLX]${RST} done"

clean:
	rm -f $(SRCOBJ)
	$(MAKE) -C $(MLXDIR) $@
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	rm -f $(NAME)
	rm -f $(MLXLIB)
	$(MAKE) -C $(FTPRINTFDIR) $@
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY: all ft_printf mlx clean fclean re
