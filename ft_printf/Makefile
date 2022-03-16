# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-der <mvan-der@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/06 13:44:38 by mvan-der      #+#    #+#                  #
#    Updated: 2022/03/16 12:14:57 by mvan-der      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ./libft/
LIBFTLIB = ./libft/libft.a

SRCS = ft_conv_csdi.c ft_conv_p.c ft_conv_uxX.c ft_count.c \
ft_printf.c ft_putchar_printf.c ft_putstr_printf.c \
ft_spec_conv.c ft_itoa_printf.c ft_utoa_printf.c

SRCOBJ = $(SRCS:.c=.o)

all: $(NAME) $(LIBFTLIB)

$(NAME): $(SRCOBJ) $(LIBFTLIB)
	cp $(LIBFTLIB) ./$(NAME)
	ar crs $(NAME) $(SRCOBJ)

%.o : %.c $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFTLIB):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -f $(SRCOBJ)
	$(MAKE) -C $(LIBFTDIR) $@

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) $@

re: fclean all

.PHONY: all libft clean fclean re
