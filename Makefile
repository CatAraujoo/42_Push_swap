# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: catarina <catarina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 09:45:18 by catarina          #+#    #+#              #
#    Updated: 2025/01/24 11:23:41 by catarina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB_NAME = libpush_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f
MAKE_CMD = make

INCLUDES_DIR = .
SRCS_DIR = .
OBJ_DIR = obj

SRCS =	$(SRCS_DIR)/push_swap.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/reverse_rotate.c \
		$(SRCS_DIR)/swap.c \
		$(SRCS_DIR)/push.c \
		$(SRCS_DIR)/big_sort.c \
		$(SRCS_DIR)/small_sort.c \
		$(SRCS_DIR)/error_check.c \
		$(SRCS_DIR)/stack_init.c \
		$(SRCS_DIR)/stack_init_a.c \
		$(SRCS_DIR)/stack_init_b.c \
		$(SRCS_DIR)/utils_stack.c 

LIBFT_DIR	= ./Libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS = $(INCLUDES_DIR)/push_swap.h

all: $(LIBFT) $(LIB_NAME) $(NAME)

$(LIBFT):
	$(MAKE_CMD) -C $(LIBFT_DIR)

$(LIB_NAME): $(OBJS)
	ar rcs $(LIB_NAME) $(OBJS)

$(NAME): $(LIB_NAME) $(OBJ_DIR)/push_swap.o
	$(CC) $(CFLAGS) $(OBJ_DIR)/push_swap.o $(LIB_NAME) $(LIBFT) -o $(NAME)



$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(DEPS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE_CMD) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(LIB_NAME) $(NAME)
	$(MAKE_CMD) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
