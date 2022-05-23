# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillmot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 12:40:09 by iwillmot          #+#    #+#              #
#    Updated: 2022/05/09 12:40:11 by iwillmot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OS = $(shell uname)

# directories
SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj

# src
SRC 	= image.c \
			main.c \
			zoom.c \
		  $(addprefix fractals/,$(shell ls $(SRCDIR)/fractals | grep -E ".+\.c"))

OBJ		= $(addprefix $(OBJDIR)/,$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
MLX		= ./mlx/
MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

MLX_INC	= -I $(MLX)
MLX_LIB	= $(addprefix $(MLX),mlx.a)

# build instructions
all: obj $(MLX_LIB) $(NAME)
	./$(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/fractals

$(OBJDIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(MLX_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) -lm -o $(NAME)

clean:
	rm $(NAME)
	rm -rf $(OBJDIR)
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all