# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: catarina <catarina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/03 09:45:18 by catarina          #+#    #+#              #
#    Updated: 2025/01/03 15:25:32 by catarina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

MAKE = make

SRCS =	$(SRCS_DIR)/push_swap.c \
		$(SRCS_DIR)/rotate.c \
		$(SRCS_DIR)/reverse_rotate.c \
		$(SRCS_DIR)/sort_stack.c \
		$(SRCS_DIR)/swap.c \
		$(SRCS_DIR)/push.c \
		$(SRCS_DIR)/main.c

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re exec