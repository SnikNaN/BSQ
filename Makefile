# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtelly <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 15:24:49 by gtelly            #+#    #+#              #
#    Updated: 2021/02/10 23:04:29 by eshana           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
HEADERS = includes
CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -O3 $(foreach h, $(HEADERS), -I$h)
SRC_DIR = srcs
OBJ_DIR = obj
SOURCES =	parse_map \
			ft_max_square_uint \
			ft_min_max_uint \
			ft_atoi \
			main \
			ft_string \
			ft_string2 \
			ft_max_square_ushort \
			ft_min_max_ushort \
			ft_max_square_uchar \
			ft_min_max_uchar \
			ft_choose \
			file_ops \
			ft_list \
			map_ops
SRC_FILE = $(addprefix $(SRC_DIR)/, $(addsuffix .c,$(SOURCES)))
OBJ_FILE = $(addprefix $(OBJ_DIR)/, $(addsuffix .o,$(SOURCES)))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_FILE)
	$(CC) $(OBJ_FILE) -o $(NAME)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
