# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/16 16:32:49 by mvan-der      #+#    #+#                  #
#    Updated: 2022/05/10 13:44:22 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADERS = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes

MLXDIR = ./mlx/
MLXLIB = libmlx.dylib
MLX = $(MLXDIR)$(MLXLIB)
FTPRINTFDIR = ./ft_printf/
FTPRINTFLIB = $(FTPRINTFDIR)libftprintf.a


SRCDIR = srcs/
OBJDIR = obj/
SRCS = so_long.c gen_utils.c image_build.c key_events.c key_hooks.c map_build.c map_check.c
SRCOBJ = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

all: $(NAME) 

$(NAME): $(SRCOBJ) $(FTPRINTFLIB) $(MLX)
	$(CC) $(SRCOBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(FTPRINTFLIB)
	cp $(MLX) ./
	@echo "${GRN}[$(NAME)]${RST} done"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(FTPRINTFLIB):
	$(MAKE) -C $(FTPRINTFDIR)
	@echo "${GRN}[FT_PRINTF + LIBFT]${RST} done"

$(MLX):
	$(MAKE) -C $(MLXDIR)
	@echo "${GRN}[MLX]${RST} done"

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(MLXDIR) $@
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	rm -f $(NAME)
	rm -f $(MLXLIB)
	$(MAKE) -C $(FTPRINTFDIR) $@
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean
	$(MAKE)

.PHONY: all ft_printf mlx clean fclean re
